/*
    BAHZ is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BAHZ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with BAHZ.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.18.0

#include <stan/model/model_header.hpp>

namespace model_bi_free_right_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_bi_free_right");
    reader.add_event(0, 0, "include", "/pre/license.stan");
    reader.add_event(0, 0, "start", "/pre/license.stan");
    reader.add_event(14, 14, "end", "/pre/license.stan");
    reader.add_event(14, 1, "restart", "model_bi_free_right");
    reader.add_event(22, 9, "include", "/data/data_binom.stan");
    reader.add_event(22, 0, "start", "/data/data_binom.stan");
    reader.add_event(28, 6, "end", "/data/data_binom.stan");
    reader.add_event(28, 10, "restart", "model_bi_free_right");
    reader.add_event(29, 11, "include", "/priors/priors_binom.stan");
    reader.add_event(29, 0, "start", "/priors/priors_binom.stan");
    reader.add_event(38, 9, "end", "/priors/priors_binom.stan");
    reader.add_event(38, 12, "restart", "model_bi_free_right");
    reader.add_event(112, 84, "end", "model_bi_free_right");
    return reader;
}

#include <meta_header.hpp>
 class model_bi_free_right : public prob_grad {
private:
    int N;
    vector<int> nFocalAllele;
    vector<int> nTotalAlleles;
    vector<double> transectDist;
    int decrease;
    int p_dist_center;
    double p_center_1;
    double p_center_2;
    double p_width_1;
    double p_width_2;
    double p_min_1;
    double p_min_2;
    double p_max_1;
    double p_max_2;
    double p_tauR_1;
    double p_tauR_2;
    double p_deltaR_1;
    double p_deltaR_2;
public:
    model_bi_free_right(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_bi_free_right(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        typedef double local_scalar_t__;

        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_bi_free_right_namespace::model_bi_free_right";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 23;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            current_statement_begin__ = 24;
            validate_non_negative_index("nFocalAllele", "N", N);
            context__.validate_dims("data initialization", "nFocalAllele", "int", context__.to_vec(N));
            validate_non_negative_index("nFocalAllele", "N", N);
            nFocalAllele = std::vector<int>(N,int(0));
            vals_i__ = context__.vals_i("nFocalAllele");
            pos__ = 0;
            size_t nFocalAllele_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < nFocalAllele_limit_0__; ++i_0__) {
                nFocalAllele[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 25;
            validate_non_negative_index("nTotalAlleles", "N", N);
            context__.validate_dims("data initialization", "nTotalAlleles", "int", context__.to_vec(N));
            validate_non_negative_index("nTotalAlleles", "N", N);
            nTotalAlleles = std::vector<int>(N,int(0));
            vals_i__ = context__.vals_i("nTotalAlleles");
            pos__ = 0;
            size_t nTotalAlleles_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < nTotalAlleles_limit_0__; ++i_0__) {
                nTotalAlleles[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 26;
            validate_non_negative_index("transectDist", "N", N);
            context__.validate_dims("data initialization", "transectDist", "double", context__.to_vec(N));
            validate_non_negative_index("transectDist", "N", N);
            transectDist = std::vector<double>(N,double(0));
            vals_r__ = context__.vals_r("transectDist");
            pos__ = 0;
            size_t transectDist_limit_0__ = N;
            for (size_t i_0__ = 0; i_0__ < transectDist_limit_0__; ++i_0__) {
                transectDist[i_0__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 27;
            context__.validate_dims("data initialization", "decrease", "int", context__.to_vec());
            decrease = int(0);
            vals_i__ = context__.vals_i("decrease");
            pos__ = 0;
            decrease = vals_i__[pos__++];
            current_statement_begin__ = 30;
            context__.validate_dims("data initialization", "p_dist_center", "int", context__.to_vec());
            p_dist_center = int(0);
            vals_i__ = context__.vals_i("p_dist_center");
            pos__ = 0;
            p_dist_center = vals_i__[pos__++];
            current_statement_begin__ = 31;
            context__.validate_dims("data initialization", "p_center_1", "double", context__.to_vec());
            p_center_1 = double(0);
            vals_r__ = context__.vals_r("p_center_1");
            pos__ = 0;
            p_center_1 = vals_r__[pos__++];
            current_statement_begin__ = 32;
            context__.validate_dims("data initialization", "p_center_2", "double", context__.to_vec());
            p_center_2 = double(0);
            vals_r__ = context__.vals_r("p_center_2");
            pos__ = 0;
            p_center_2 = vals_r__[pos__++];
            current_statement_begin__ = 33;
            context__.validate_dims("data initialization", "p_width_1", "double", context__.to_vec());
            p_width_1 = double(0);
            vals_r__ = context__.vals_r("p_width_1");
            pos__ = 0;
            p_width_1 = vals_r__[pos__++];
            current_statement_begin__ = 34;
            context__.validate_dims("data initialization", "p_width_2", "double", context__.to_vec());
            p_width_2 = double(0);
            vals_r__ = context__.vals_r("p_width_2");
            pos__ = 0;
            p_width_2 = vals_r__[pos__++];
            current_statement_begin__ = 35;
            context__.validate_dims("data initialization", "p_min_1", "double", context__.to_vec());
            p_min_1 = double(0);
            vals_r__ = context__.vals_r("p_min_1");
            pos__ = 0;
            p_min_1 = vals_r__[pos__++];
            current_statement_begin__ = 36;
            context__.validate_dims("data initialization", "p_min_2", "double", context__.to_vec());
            p_min_2 = double(0);
            vals_r__ = context__.vals_r("p_min_2");
            pos__ = 0;
            p_min_2 = vals_r__[pos__++];
            current_statement_begin__ = 37;
            context__.validate_dims("data initialization", "p_max_1", "double", context__.to_vec());
            p_max_1 = double(0);
            vals_r__ = context__.vals_r("p_max_1");
            pos__ = 0;
            p_max_1 = vals_r__[pos__++];
            current_statement_begin__ = 38;
            context__.validate_dims("data initialization", "p_max_2", "double", context__.to_vec());
            p_max_2 = double(0);
            vals_r__ = context__.vals_r("p_max_2");
            pos__ = 0;
            p_max_2 = vals_r__[pos__++];
            current_statement_begin__ = 40;
            context__.validate_dims("data initialization", "p_tauR_1", "double", context__.to_vec());
            p_tauR_1 = double(0);
            vals_r__ = context__.vals_r("p_tauR_1");
            pos__ = 0;
            p_tauR_1 = vals_r__[pos__++];
            current_statement_begin__ = 41;
            context__.validate_dims("data initialization", "p_tauR_2", "double", context__.to_vec());
            p_tauR_2 = double(0);
            vals_r__ = context__.vals_r("p_tauR_2");
            pos__ = 0;
            p_tauR_2 = vals_r__[pos__++];
            current_statement_begin__ = 42;
            context__.validate_dims("data initialization", "p_deltaR_1", "double", context__.to_vec());
            p_deltaR_1 = double(0);
            vals_r__ = context__.vals_r("p_deltaR_1");
            pos__ = 0;
            p_deltaR_1 = vals_r__[pos__++];
            current_statement_begin__ = 43;
            context__.validate_dims("data initialization", "p_deltaR_2", "double", context__.to_vec());
            p_deltaR_2 = double(0);
            vals_r__ = context__.vals_r("p_deltaR_2");
            pos__ = 0;
            p_deltaR_2 = vals_r__[pos__++];

            // validate, data variables
            current_statement_begin__ = 23;
            check_greater_or_equal(function__,"N",N,1);
            current_statement_begin__ = 24;
            current_statement_begin__ = 25;
            current_statement_begin__ = 26;
            current_statement_begin__ = 27;
            check_greater_or_equal(function__,"decrease",decrease,0);
            check_less_or_equal(function__,"decrease",decrease,1);
            current_statement_begin__ = 30;
            check_less_or_equal(function__,"p_dist_center",p_dist_center,1);
            current_statement_begin__ = 31;
            current_statement_begin__ = 32;
            current_statement_begin__ = 33;
            current_statement_begin__ = 34;
            current_statement_begin__ = 35;
            current_statement_begin__ = 36;
            current_statement_begin__ = 37;
            current_statement_begin__ = 38;
            current_statement_begin__ = 40;
            current_statement_begin__ = 41;
            current_statement_begin__ = 42;
            current_statement_begin__ = 43;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 47;
            ++num_params_r__;
            current_statement_begin__ = 48;
            ++num_params_r__;
            current_statement_begin__ = 49;
            ++num_params_r__;
            current_statement_begin__ = 50;
            ++num_params_r__;
            current_statement_begin__ = 51;
            ++num_params_r__;
            current_statement_begin__ = 52;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_bi_free_right() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("center")))
            throw std::runtime_error("variable center missing");
        vals_r__ = context__.vals_r("center");
        pos__ = 0U;
        context__.validate_dims("initialization", "center", "double", context__.to_vec());
        double center(0);
        center = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(center);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable center: ") + e.what());
        }

        if (!(context__.contains_r("width")))
            throw std::runtime_error("variable width missing");
        vals_r__ = context__.vals_r("width");
        pos__ = 0U;
        context__.validate_dims("initialization", "width", "double", context__.to_vec());
        double width(0);
        width = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,width);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable width: ") + e.what());
        }

        if (!(context__.contains_r("pmin")))
            throw std::runtime_error("variable pmin missing");
        vals_r__ = context__.vals_r("pmin");
        pos__ = 0U;
        context__.validate_dims("initialization", "pmin", "double", context__.to_vec());
        double pmin(0);
        pmin = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain(0,1,pmin);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable pmin: ") + e.what());
        }

        if (!(context__.contains_r("pmax")))
            throw std::runtime_error("variable pmax missing");
        vals_r__ = context__.vals_r("pmax");
        pos__ = 0U;
        context__.validate_dims("initialization", "pmax", "double", context__.to_vec());
        double pmax(0);
        pmax = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain(0,1,pmax);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable pmax: ") + e.what());
        }

        if (!(context__.contains_r("deltaR")))
            throw std::runtime_error("variable deltaR missing");
        vals_r__ = context__.vals_r("deltaR");
        pos__ = 0U;
        context__.validate_dims("initialization", "deltaR", "double", context__.to_vec());
        double deltaR(0);
        deltaR = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,deltaR);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable deltaR: ") + e.what());
        }

        if (!(context__.contains_r("tauR")))
            throw std::runtime_error("variable tauR missing");
        vals_r__ = context__.vals_r("tauR");
        pos__ = 0U;
        context__.validate_dims("initialization", "tauR", "double", context__.to_vec());
        double tauR(0);
        tauR = vals_r__[pos__++];
        try {
            writer__.scalar_lub_unconstrain(0,1,tauR);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable tauR: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        typedef T__ local_scalar_t__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);

            local_scalar_t__ center;
            (void) center;  // dummy to suppress unused var warning
            if (jacobian__)
                center = in__.scalar_constrain(lp__);
            else
                center = in__.scalar_constrain();

            local_scalar_t__ width;
            (void) width;  // dummy to suppress unused var warning
            if (jacobian__)
                width = in__.scalar_lb_constrain(0,lp__);
            else
                width = in__.scalar_lb_constrain(0);

            local_scalar_t__ pmin;
            (void) pmin;  // dummy to suppress unused var warning
            if (jacobian__)
                pmin = in__.scalar_lub_constrain(0,1,lp__);
            else
                pmin = in__.scalar_lub_constrain(0,1);

            local_scalar_t__ pmax;
            (void) pmax;  // dummy to suppress unused var warning
            if (jacobian__)
                pmax = in__.scalar_lub_constrain(0,1,lp__);
            else
                pmax = in__.scalar_lub_constrain(0,1);

            local_scalar_t__ deltaR;
            (void) deltaR;  // dummy to suppress unused var warning
            if (jacobian__)
                deltaR = in__.scalar_lb_constrain(0,lp__);
            else
                deltaR = in__.scalar_lb_constrain(0);

            local_scalar_t__ tauR;
            (void) tauR;  // dummy to suppress unused var warning
            if (jacobian__)
                tauR = in__.scalar_lub_constrain(0,1,lp__);
            else
                tauR = in__.scalar_lub_constrain(0,1);


            // transformed parameters
            current_statement_begin__ = 56;
            validate_non_negative_index("p", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  p(static_cast<Eigen::VectorXd::Index>(N));
            (void) p;  // dummy to suppress unused var warning

            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p,DUMMY_VAR__);


            current_statement_begin__ = 57;
            for (int i = 1; i <= N; ++i) {

                current_statement_begin__ = 59;
                if (as_bool(logical_gte(get_base1(transectDist,i,"transectDist",1),(center + deltaR)))) {

                    current_statement_begin__ = 61;
                    if (as_bool(logical_eq(decrease,0))) {

                        current_statement_begin__ = 62;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * (1 - ((1 / (1 + stan::math::exp(((4 * deltaR) / width)))) * stan::math::exp(((((-(4) * tauR) * ((get_base1(transectDist,i,"transectDist",1) - center) - deltaR)) / width) / (1 + stan::math::exp(((-(4) * deltaR) / width))))))))), 
                                    "assigning variable p");
                    }
                    current_statement_begin__ = 64;
                    if (as_bool(logical_eq(decrease,1))) {

                        current_statement_begin__ = 65;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * ((1 / (1 + stan::math::exp(((4 * deltaR) / width)))) * stan::math::exp(((((-(4) * tauR) * ((get_base1(transectDist,i,"transectDist",1) - center) - deltaR)) / width) / (1 + stan::math::exp(((-(4) * deltaR) / width)))))))), 
                                    "assigning variable p");
                    }
                } else {

                    current_statement_begin__ = 69;
                    if (as_bool(logical_eq(decrease,0))) {

                        current_statement_begin__ = 70;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * (stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width)) / (1 + stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width)))))), 
                                    "assigning variable p");
                    }
                    current_statement_begin__ = 72;
                    if (as_bool(logical_eq(decrease,1))) {

                        current_statement_begin__ = 73;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * (1 - (stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width)) / (1 + stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width))))))), 
                                    "assigning variable p");
                    }
                }
            }

            // validate transformed parameters
            for (int i0__ = 0; i0__ < N; ++i0__) {
                if (stan::math::is_uninitialized(p(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: p" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 56;

            // model body

            current_statement_begin__ = 81;
            lp_accum__.add(uniform_log<propto__>(tauR, p_tauR_1, p_tauR_2));
            current_statement_begin__ = 82;
            lp_accum__.add(exponential_log<propto__>(deltaR, p_deltaR_1));
            current_statement_begin__ = 83;
            lp_accum__.add(uniform_log<propto__>(pmax, p_max_1, p_max_2));
            current_statement_begin__ = 84;
            lp_accum__.add(uniform_log<propto__>(pmin, p_min_1, p_min_2));
            current_statement_begin__ = 85;
            lp_accum__.add(normal_log<propto__>(width, p_width_1, p_width_2));
            current_statement_begin__ = 86;
            if (as_bool(logical_eq(p_dist_center,0))) {

                current_statement_begin__ = 87;
                lp_accum__.add(normal_log<propto__>(center, p_center_1, p_center_2));
            }
            current_statement_begin__ = 89;
            if (as_bool(logical_eq(p_dist_center,1))) {

                current_statement_begin__ = 90;
                lp_accum__.add(uniform_log<propto__>(center, p_center_1, p_center_2));
            }
            current_statement_begin__ = 95;
            lp_accum__.add(binomial_log<propto__>(nFocalAllele, nTotalAlleles, p));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("center");
        names__.push_back("width");
        names__.push_back("pmin");
        names__.push_back("pmax");
        names__.push_back("deltaR");
        names__.push_back("tauR");
        names__.push_back("p");
        names__.push_back("dev");
        names__.push_back("log_lik");
        names__.push_back("y_rep");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        typedef double local_scalar_t__;

        vars__.resize(0);
        stan::io::reader<local_scalar_t__> in__(params_r__,params_i__);
        static const char* function__ = "model_bi_free_right_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double center = in__.scalar_constrain();
        double width = in__.scalar_lb_constrain(0);
        double pmin = in__.scalar_lub_constrain(0,1);
        double pmax = in__.scalar_lub_constrain(0,1);
        double deltaR = in__.scalar_lb_constrain(0);
        double tauR = in__.scalar_lub_constrain(0,1);
        vars__.push_back(center);
        vars__.push_back(width);
        vars__.push_back(pmin);
        vars__.push_back(pmax);
        vars__.push_back(deltaR);
        vars__.push_back(tauR);

        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 56;
            validate_non_negative_index("p", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  p(static_cast<Eigen::VectorXd::Index>(N));
            (void) p;  // dummy to suppress unused var warning

            stan::math::initialize(p, DUMMY_VAR__);
            stan::math::fill(p,DUMMY_VAR__);


            current_statement_begin__ = 57;
            for (int i = 1; i <= N; ++i) {

                current_statement_begin__ = 59;
                if (as_bool(logical_gte(get_base1(transectDist,i,"transectDist",1),(center + deltaR)))) {

                    current_statement_begin__ = 61;
                    if (as_bool(logical_eq(decrease,0))) {

                        current_statement_begin__ = 62;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * (1 - ((1 / (1 + stan::math::exp(((4 * deltaR) / width)))) * stan::math::exp(((((-(4) * tauR) * ((get_base1(transectDist,i,"transectDist",1) - center) - deltaR)) / width) / (1 + stan::math::exp(((-(4) * deltaR) / width))))))))), 
                                    "assigning variable p");
                    }
                    current_statement_begin__ = 64;
                    if (as_bool(logical_eq(decrease,1))) {

                        current_statement_begin__ = 65;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * ((1 / (1 + stan::math::exp(((4 * deltaR) / width)))) * stan::math::exp(((((-(4) * tauR) * ((get_base1(transectDist,i,"transectDist",1) - center) - deltaR)) / width) / (1 + stan::math::exp(((-(4) * deltaR) / width)))))))), 
                                    "assigning variable p");
                    }
                } else {

                    current_statement_begin__ = 69;
                    if (as_bool(logical_eq(decrease,0))) {

                        current_statement_begin__ = 70;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * (stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width)) / (1 + stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width)))))), 
                                    "assigning variable p");
                    }
                    current_statement_begin__ = 72;
                    if (as_bool(logical_eq(decrease,1))) {

                        current_statement_begin__ = 73;
                        stan::model::assign(p, 
                                    stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                                    (pmin + ((pmax - pmin) * (1 - (stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width)) / (1 + stan::math::exp(((4 * (get_base1(transectDist,i,"transectDist",1) - center)) / width))))))), 
                                    "assigning variable p");
                    }
                }
            }

            // validate transformed parameters
            current_statement_begin__ = 56;

            // write transformed parameters
            if (include_tparams__) {
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(p[k_0__]);
            }
            }
            if (!include_gqs__) return;
            // declare and define generated quantities
            current_statement_begin__ = 99;
            local_scalar_t__ dev;
            (void) dev;  // dummy to suppress unused var warning

            stan::math::initialize(dev, DUMMY_VAR__);
            stan::math::fill(dev,DUMMY_VAR__);
            current_statement_begin__ = 100;
            validate_non_negative_index("log_lik", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  log_lik(static_cast<Eigen::VectorXd::Index>(N));
            (void) log_lik;  // dummy to suppress unused var warning

            stan::math::initialize(log_lik, DUMMY_VAR__);
            stan::math::fill(log_lik,DUMMY_VAR__);
            current_statement_begin__ = 101;
            validate_non_negative_index("y_rep", "N", N);
            Eigen::Matrix<local_scalar_t__,Eigen::Dynamic,1>  y_rep(static_cast<Eigen::VectorXd::Index>(N));
            (void) y_rep;  // dummy to suppress unused var warning

            stan::math::initialize(y_rep, DUMMY_VAR__);
            stan::math::fill(y_rep,DUMMY_VAR__);


            current_statement_begin__ = 102;
            for (int i = 1; i <= N; ++i) {

                current_statement_begin__ = 104;
                stan::model::assign(log_lik, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            binomial_log(get_base1(nFocalAllele,i,"nFocalAllele",1),get_base1(nTotalAlleles,i,"nTotalAlleles",1),get_base1(p,i,"p",1)), 
                            "assigning variable log_lik");
                current_statement_begin__ = 106;
                stan::model::assign(y_rep, 
                            stan::model::cons_list(stan::model::index_uni(i), stan::model::nil_index_list()), 
                            binomial_rng(get_base1(nTotalAlleles,i,"nTotalAlleles",1),get_base1(p,i,"p",1), base_rng__), 
                            "assigning variable y_rep");
            }
            current_statement_begin__ = 109;
            stan::math::assign(dev, (-(2) * binomial_log(nFocalAllele,nTotalAlleles,p)));

            // validate generated quantities
            current_statement_begin__ = 99;
            current_statement_begin__ = 100;
            current_statement_begin__ = 101;

            // write generated quantities
        vars__.push_back(dev);
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(log_lik[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(y_rep[k_0__]);
            }

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_bi_free_right";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "center";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "width";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "pmin";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "pmax";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "deltaR";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tauR";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "p" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "dev";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y_rep" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "center";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "width";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "pmin";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "pmax";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "deltaR";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "tauR";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (include_tparams__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "p" << '.' << k_0__;
                param_names__.push_back(param_name_stream__.str());
            }
        }


        if (!include_gqs__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "dev";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "log_lik" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y_rep" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
    }

}; // model

}

typedef model_bi_free_right_namespace::model_bi_free_right stan_model;


#endif
