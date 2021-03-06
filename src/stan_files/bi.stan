#include /pre/license.stan

data {

#include /data/data_binom.stan
#include /priors/priors_all.stan
#include /priors/priors_left_tail.stan
#include /priors/priors_right_tail.stan
#include /priors/priors_mirror_tail.stan

}

parameters{

#include /parameters/param_all.stan
#include /parameters/param_left_tail.stan
#include /parameters/param_right_tail.stan
#include /parameters/param_mirror_tail.stan

}

transformed parameters {
  vector<lower=0, upper=1>[N] p; // the allele frequency at each site
  for ( i in 1:N )
  { // for each site
      if (decrease == 0) // if increasing
      {
        if (tails == 1) // if left tail model
        {
          if (transectDist[i] <= center - deltaL) // if inside tail
          {
            p[i] =  pmin + (pmax-pmin)*(1/(1 + exp(4*deltaL/width)))*exp((4*tauL*(transectDist[i] - center + deltaL)/width)/(1 + exp(-4*deltaL/width)));
          }
          else // not in tail, use regular equation.
          {
            p[i] =   pmin + (pmax - pmin) * (exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width)));
          }
        }
        else if (tails == 2) // if right tail model
        {
          if (transectDist[i] >= center + deltaR) // if inside tail
          {
            p[i] =  pmin + (pmax-pmin)*(1-(1/(1 + exp(4*deltaR/width)))*exp((-4*tauR*(transectDist[i] - center - deltaR)/width)/(1 + exp(-4*deltaR/width))));
          }
          else // not in tail, use regular equation.
          {
            p[i] =   pmin + (pmax - pmin) * (exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width)));
          }
        }
        else if (tails == 3) // if mirror tail model
        {
          if (transectDist[i] <= center - deltaM) // if inside left tail
          {
            p[i] =  pmin + (pmax-pmin)*(1/(1 + exp(4*deltaM/width)))*exp((4*tauM*(transectDist[i] - center + deltaM)/width)/(1 + exp(-4*deltaM/width)));
          }
          else if (transectDist[i] >= center + deltaM)  // if inside right tail
          {
            p[i] =  pmin + (pmax-pmin)*(1-(1/(1 + exp(4*deltaM/width)))*exp((-4*tauM*(transectDist[i] - center - deltaM)/width)/(1 + exp(-4*deltaM/width))));
          }
          else
          {
            p[i] =   pmin + (pmax - pmin) * (exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width)));
          }
        }
        else if (tails == 4) // if ind tail model
        {
          if (transectDist[i] <= center - deltaL) // if in left tail
          {
            p[i] =  pmin + (pmax-pmin)*(1/(1 + exp(4*deltaL/width)))*exp((4*tauL*(transectDist[i] - center + deltaL)/width)/(1 + exp(-4*deltaL/width)));
          }
          else if (transectDist[i] >= center + deltaR) // if in right tail
          {
            p[i] =  pmin + (pmax-pmin)*(1-(1/(1 + exp(4*deltaR/width)))*exp((-4*tauR*(transectDist[i] - center - deltaR)/width)/(1 + exp(-4*deltaR/width))));
          }
          else // not in tail, use regular equation.
          {
          p[i] =   pmin + (pmax - pmin) * (exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width)));
          }
        }
        else // no tail model, use regular equation
        {
          p[i] =   pmin + (pmax - pmin) * (exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width)));
       }
      }
       if (decrease == 1) // if decreasing
      {
        if (tails == 1) // if left tail model
        {
          if (transectDist[i] <= center - deltaL) // if inside tail
          {
            p[i] =  pmin + (pmax-pmin)*(1-(1/(1 + exp(4*deltaL/width)))*exp((4*tauL*(transectDist[i] - center + deltaL)/width)/(1 + exp(-4*deltaL/width))));
          }
          else // not in tail, use regular equation.
          {
            p[i] =   pmin + (pmax - pmin) * (1-(exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width))));
          }
        }
        else if (tails == 2) // if right tail model
        {
          if (transectDist[i] >= center + deltaR) // if inside tail
          {
            p[i] =  pmin + (pmax-pmin)*((1/(1 + exp(4*deltaR/width)))*exp((-4*tauR*(transectDist[i] - center - deltaR)/width)/(1 + exp(-4*deltaR/width))));
          }
          else // not in tail, use regular equation.
          {
            p[i] =   pmin + (pmax - pmin) * (1-(exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width))));
          }
        }
        else if (tails == 3) // if mirror tail model
        {
          if (transectDist[i] <= center - deltaM) // if inside left tail
          {
            p[i] =  pmin + (pmax-pmin)*(1-(1/(1 + exp(4*deltaM/width)))*exp((4*tauM*(transectDist[i] - center + deltaM)/width)/(1 + exp(-4*deltaM/width))));
          }
          else if (transectDist[i] >= center + deltaM)  // if inside right tail
          {
            p[i] =  pmin + (pmax-pmin)*((1/(1 + exp(4*deltaM/width)))*exp((-4*tauM*(transectDist[i] - center - deltaM)/width)/(1 + exp(-4*deltaM/width))));
          }
          else
          {
            p[i] =   pmin + (pmax - pmin) * (1-(exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width))));
          }
        }
        else if (tails == 4) // if ind tail model
        {
          if (transectDist[i] <= center - deltaL) // if in left tail
          {
            p[i] =  pmin + (pmax-pmin)*(1-(1/(1 + exp(4*deltaL/width)))*exp((4*tauL*(transectDist[i] - center + deltaL)/width)/(1 + exp(-4*deltaL/width))));
          }
          else if (transectDist[i] >= center + deltaR) // if in right tail
          {
            p[i] =  pmin + (pmax-pmin)*((1/(1 + exp(4*deltaR/width)))*exp((-4*tauR*(transectDist[i] - center - deltaR)/width)/(1 + exp(-4*deltaR/width))));
          }
          else // not in tail, use regular equation.
          {
          p[i] =   pmin + (pmax - pmin) * (1-(exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width))));
          }
        }
        else // no tail model, use regular equation
        {
          p[i] =   pmin + (pmax - pmin) * (1-(exp(4*(transectDist[i] - center)/width)/(1 + exp(4 * (transectDist[i] - center)/width))));
       }
      }
  }
}

model{
  // The statistical model

#include /model/model_mirror_tail.stan
#include /model/model_left_tail.stan
#include /model/model_right_tail.stan
#include /model/model_ps.stan
#include /model/model_width.stan
#include /model/model_center.stan


  // and the likelihood: observed allele counts follow a binomial liklihood,
  // based on the number of alleles sampled and the estimated allele frequency.
  nFocalAllele ~ binomial(nTotalAlleles, p);
}
generated quantities{

#include /generated_quantities/gen_quant_binomial.stan

}
