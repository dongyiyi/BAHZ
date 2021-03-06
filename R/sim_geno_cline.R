#' Simulate genetic data from a cline
#'
#' This function generates a dataframe with simulated genotypic data sampled
#' from a genetic cline. The sampling sites, number of individuals, level of
#' inbreeding, and cline parameters are supplied by the user. Cline parameters
#' are flexible, and can model both sigmoid clines and stepped clines with
#' introgresison tails.
#'
#' This function calls \code{\link{general_cline_eqn}} for each sampled point along the
#' cline to generate the expected allele frequency at that point. The calculated
#' allele frequency and provided Fis are then used to calculate the expected
#' genotype frequencies for each site, according to the equations:
#'
#' \deqn{AA = p^2 + p(1-p)Fis}
#' \deqn{Aa = 2p(1-p)(1-Fis)}
#' \deqn{aa = (1-p)^2 + p(1-p)Fis}
#'
#' Sampled genotypes are then drawn from a multinomial distribution, with the
#' expected genotype frequencies as the probabilities. From those sampled
#' genotypes, empirical allele frequencies (emp.p) and empirical Fis estimates
#' (emp.f) are calculated as:
#'
#' \deqn{emp.p = (2*AA + Aa)/N}
#' \deqn{emp.f = (Hexp - Hobs)/Hexp}
#'
#' where AA is the number of honozygotes of the focal allele, Aa is the number
#' of heterozygotes, N is the number of sampled individuals, and  Hexp and Hobs
#' are the expected and observed heterozygosity. Fis values are corrected with
#' \link{correct_fis}, such that empirical Fis values which are undefined or < 0
#' are corrected to 0.
#'
#' @importFrom stats "rmultinom"
#' @importFrom magrittr "%>%"
#'
#' @param transect_distances The distances along the transect for the simulated
#'   sampling sites. A numeric vector.
#' @param n_ind The number of diploid individuals sampled at each site. Either a
#'   single numeric value (for constant sampling), or a numeric vector equal in
#'   length to \code{transect_distances}.
#' @param Fis The inbreeding coefficient, Fis, for each site. Must be between 0
#'   and 1 (inclusive). Either a single numeric value (for constant inbreeding),
#'   or a numeric vector equal in length to \code{transect_distances}.
#' @param decrease Is the cline decreasing in frequency? \code{TRUE} or
#'   \code{FALSE}.
#' @param center The location of the cline center, in the same distance units as
#'   \code{transect_distances}. Numeric, must be greater than 0.
#' @param width The width of the cline, in the same distance units as
#'   \code{transect_distances}. Numeric, must be greater than 0.
#' @param pmin,pmax Optional. The minimum and maximum allele frequency values
#'   in the tails of the cline. Default values are \code{0} and \code{1}, respectively.
#'   Must be between 0 and 1 (inclusive). Numeric.
#' @param deltaL,tauL Optional delta and tau parameters which describe the left
#'   exponential tail. Must supply both to generate a tail. Default is \code{NULL} (no
#'   tails). Numeric. tauL must be between 0 and 1 (inclusive).
#' @param deltaR,tauR Optional delta and tau parameters which describe the right
#'   exponential tail. Must supply both to generate a tail. Default is \code{NULL} (no
#'   tails). Numeric. tauR must be between 0 and 1 (inclusive).
#'
#'
#' @return A data frame of simulated genetic data sampled from the cline. Columns are:
#'     \itemize{
#'     \item site: The site numbers, given sequentially starting at 1.
#'     \item transectDist: The distance along the cline for each site.
#'     \item cline.p: The expected allele frequency for each site, given its position on the cline.
#'     \item cline.f: The expected coefficient of inbreeding for each site.
#'     \item AA, Aa, aa: The simulated number of homozygotes and heterozygotes for each site.
#'     \item N: The number of individuals sampled for each site.
#'     \item emp.p: The observed allele frequency for each site (includes sampling error).
#'     \item emp.f: The observed Fis for each site (includes sampling error).
#' }
#'
#' @export
#'
#' @examples
#' # Simulate genotype data from a decreasing cline
#' # with center at 100, width of 30.
#' # Sites are 20 units apart, from 0 to 200.
#' # 20 individuals are sampled at each site.
#' # Inbreeding is constant at Fis = 0.1.
#'
#' set.seed(123)
#' sim_geno_cline(transect_distance = seq(0,200,20),
#'                n_ind = 20, Fis = 0.1,
#'                decrease = TRUE,
#'                center = 100, width = 30)
#'
#' # Simulate genotype data from an increasing cline
#' # with center at 272, width of 91.
#' # The minimum and maximum allele frequencies
#' # are 0.07 and 0.98, respectively, and
#' # there is an introgression tail on the
#' # left side with deltaL = 29 and tauL = 0.8.
#'
#' # Sites are 13 units apart, from 162 to 312.
#' # At each site, the number of individuals sampled
#' # is drawn from a random normal distribution with
#' # mean = 25 and sd = 5
#' # Inbreeding is constant at Fis = 0.
#'
#' set.seed(123)
#' ind_sampling <- as.integer(rnorm(length(seq(162,312,12)), 25, 5))
#' sim_geno_cline(transect_distance = seq(162,312,12),
#'                n_ind = ind_sampling,
#'                Fis = 0, decrease = FALSE,
#'                center = 272, width = 91,
#'                pmin = 0.07, pmax = 0.98,
#'                deltaL = 29, tauL = 0.8)
#'

sim_geno_cline <- function(transect_distances, n_ind,
                                Fis, decrease,
                                center, width,
                                pmin = 0, pmax = 1,
                                deltaL = NULL, tauL = NULL,
                                deltaR = NULL, tauR = NULL) {


  # Check the sampling and inbreeding options
  for (vec.arg in alist(n_ind, Fis)) {
    assertthat::assert_that(is.vector(eval(vec.arg)) == T,
                msg = paste(vec.arg, "must be a vector", sep = " "))
    assertthat::assert_that(is.numeric(eval(vec.arg)) == T,
                msg = paste(vec.arg, "must be numeric", sep = " "))
    assertthat::assert_that((length(eval(vec.arg)) %in% c(1, length(transect_distances))) == T,
               msg = paste(vec.arg, " must be either be of length 1, for constant ", vec.arg,
                           ", or must match the length of transect_distances (",
                           length(transect_distances), sep = ""))
  }
  assertthat::assert_that(min(Fis) >=0, msg = "Fis values cannot be less than 0")
  assertthat::assert_that(min(Fis) <=1, msg = "Fis values cannot be greater than 1")
  assertthat::assert_that(min(n_ind) >=1, msg = "n_ind values cannot be less than 1")

  # For geno, check limits of pmin and pmax
  for (num.arg in alist(pmin, pmax)) {
    if (is.null(eval(num.arg)) == F) {
      assertthat::assert_that(eval(num.arg) >= 0, msg = paste(num.arg, " must be between 0 and 1 (inclusive)", sep = ""))
      assertthat::assert_that(eval(num.arg) <= 1, msg = paste(num.arg, " must be between 0 and 1 (inclusive)", sep = ""))
    }
  }
  # All other args will get checked in the cline equation.

  # Get number of sites from the vector of transect data.
  sites <- length(unique(transect_distances))
  # Get the vector of f values for each site
  if (length(n_ind) == 1) {
    Ns <- as.integer(rep(n_ind, times = sites))
  } else {
    Ns <- as.integer(n_ind)
  }
  if (length(Fis) == 1) {
    fs <- rep(Fis, times = sites)
  } else {
    fs <- Fis
  }

  # Make the empty results data frame
  fk.dt <- data.frame(site = 1:sites,
                      transectDist = transect_distances,
                      cline.p = rep(NA, times = sites),
                      cline.f = fs,
                      AA = rep(NA, times = sites),
                      Aa = rep(NA, times = sites),
                      aa = rep(NA, times = sites),
                      N = Ns)

  # Add the predicted cline p to each row
  fk.dt$cline.p <- general_cline_eqn(transectDist = fk.dt$transectDist,
                                          center = center,
                                          width = width,
                                          pmin = pmin,
                                          pmax = pmax,
                                          deltaL = deltaL,
                                          deltaR = deltaR,
                                          tauL = tauL,
                                          tauR = tauR,
                                          decrease = decrease)
  # Then add the simulated genotypes to each row
  # Would be nice to vectorize this somehow, but I haven't figured out a nice easy way

  for (row in 1:sites) {
    AA <- fk.dt$cline.p[row]^2 + fk.dt$cline.f[row]*fk.dt$cline.p[row]*(1-fk.dt$cline.p[row])
    Aa <- 2*fk.dt$cline.p[row]*(1-fk.dt$cline.p[row])*(1-fk.dt$cline.f[row])
    aa <- (1-fk.dt$cline.p[row])^2 +fk.dt$cline.f[row]*fk.dt$cline.p[row]*(1-fk.dt$cline.p[row])
    genotypes <- rowSums(stats::rmultinom(n = 1, size = fk.dt$N[row], prob = c(AA, Aa, aa)))
    fk.dt$AA[row] <- as.integer(genotypes[1])
    fk.dt$Aa[row] <- as.integer(genotypes[2])
    fk.dt$aa[row] <- as.integer(genotypes[3])
  }


# Calculate empirical p and Fis value from the simulated data
fk.dt <- fk.dt %>%
  dplyr::mutate(emp.p = (2*.data$AA + .data$Aa)/(2*.data$N)) %>%
  dplyr::mutate(Hexp = 2*.data$emp.p*(1-.data$emp.p),
                Hobs = .data$Aa/.data$N) %>%
  dplyr::mutate(Fis = (.data$Hexp - .data$Hobs)/.data$Hexp) %>%
  correct_fis(.) %>%
  dplyr::rename(emp.f = .data$Fis) %>%
  dplyr::select(-.data$Hexp, -.data$Hobs)

  # Do some rounding to 3 decimal places
  fk.dt$cline.p <- round(fk.dt$cline.p, digits = 3)
  fk.dt$emp.p <- round(fk.dt$emp.p, digits = 3)
  fk.dt$emp.f <- round(fk.dt$emp.f, digits = 3)
  fk.dt
}
