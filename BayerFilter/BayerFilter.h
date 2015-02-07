//
//  BayerFilter.h
//  BayerFilter
//
//  Created by FurutaYuki on 2/6/15.
//  Copyright (c) 2015 Furushchev. All rights reserved.
//

#ifndef __BayerFilter__BayerFilter__
#define __BayerFilter__BayerFilter__

#include <opencv2/core/core.hpp>
#include <cstdint>

namespace BayerFilter {
    enum BayerPattern : int {
        BG = 1,
        GB,
        RG,
        GR,
    };
    
    void cvtToBayerImage(const cv::Mat &src, cv::Mat &dst, BayerPattern pattern=BG);
}

#endif /* defined(__BayerFilter__BayerFilter__) */
