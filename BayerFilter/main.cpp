//
//  main.cpp
//  BayerFilter
//
//  Created by FurutaYuki on 2/6/15.
//  Copyright (c) 2015 Furushchev. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

#include "BayerFilter.h"

int main(int argc, const char * argv[]) {

    auto src = cv::imread("./moscow.jpg");
    std::cout << "w: " << src.size().width << ", h: " << src.size().height << std::endl;
    cv::imshow("src", src);

    cv::Mat dst;
    
    BayerFilter::cvtToBayerImage(src, dst, BayerFilter::BayerPattern::BG);
    
    cv::imshow("dst", dst);
    
    cv::Mat dst2;

    cv::cvtColor(dst, dst2, CV_BayerBG2BGR);
    
    cv::imshow("dst2", dst2);
    
    cv::waitKey(0);
    return 0;
}
