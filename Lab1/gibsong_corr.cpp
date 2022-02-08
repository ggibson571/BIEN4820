#include "gibsong_corr.hpp"
#include "gibsong_stats.cpp"
using namespace arrStats;

arrStats::corrs::corrs() {
    ;
}
float arrStats::corrs::corr_coef(std::vector<float>* data1, std::vector<float>* data2) {
    int limit_size = data1->size();
    if(data1->size() >= data2->size()) {
         limit_size = data2->size();
    }
    arrStats::basicStats stat_obj(1);
    float mean1 = stat_obj.mean(data1);
    float mean2 = stat_obj.mean(data2);
    float mean1_sq = data1->size()*pow(mean1, 2);
    float mean2_sq = data2->size()*pow(mean2, 2);
    float sumxy = 0;
    float sumx_sq = 0;
    float sumy_sq = 0;
    std::vector<float> comb_vec(*data1);
    comb_vec.insert(data1->end(), data2->begin(), data2->end());
    float comb_mean = stat_obj.mean(&comb_vec);
    //float comb_mean = (data1->size()*mean1 + data2->size()*mean2)/(data1->size()+data2->size());
    //comb_mean = comb_mean * limit_size;
    for(int i = 0; i < limit_size; i++) {
        sumxy = (data1->at(i) * data2->at(i)) + sumxy;
        sumx_sq = sumx_sq + pow(data1->at(i), 2);
        sumy_sq = sumy_sq + pow(data2->at(i), 2);

    }
    float cor_co = (sumxy - comb_mean)/sqrt((sumx_sq-mean1_sq)*(sumy_sq-mean2_sq));
    return cor_co;
}