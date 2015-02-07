//
//  BayerFilter.cpp
//  BayerFilter
//
//  Created by FurutaYuki on 2/6/15.
//  Copyright (c) 2015 Furushchev. All rights reserved.
//

#include "BayerFilter.h"
#include <iostream>

namespace BayerFilter {

    void cvtToBayerImage(const cv::Mat &src, cv::Mat &dst, BayerPattern pattern)
    {
        CV_Assert(src.channels() == 3);
        CV_Assert(src.depth() == CV_8U);

        dst = cv::Mat::zeros(src.size(), CV_8UC1);
        
        bool blueLine = false, greenStart = false;
        switch (pattern) {
            case BayerPattern::BG:
                blueLine = false;
                greenStart = false;
                break;
            case BayerPattern::GR:
                blueLine = true;
                greenStart = true;
                break;
            case BayerPattern::GB:
                blueLine = false;
                greenStart = true;
                break;
            case BayerPattern::RG:
                blueLine = true;
                greenStart = false;
                break;
            default:
                break;
        }
        for (int y = 0; y < dst.rows; ++y) {
            bool green = greenStart;
            for (int x = 0; x < dst.cols; ++x) {
                auto p = src.at<cv::Vec3b>(y,x);
                
                int idx = 0; // b
                if (green) idx = 1; // g
                else if (!blueLine && !green) idx = 2; // r

                dst.at<uint8_t>(y,x) = p[idx];
                
                green = !green;
            }
            greenStart = !greenStart;
            blueLine = !blueLine;
        }
    }
    
}