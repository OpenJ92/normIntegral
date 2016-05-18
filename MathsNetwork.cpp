// MathsNetwork.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>

#define PI (3.141592653589793)

cv::Mat result(500, 500, CV_8UC3, cv::Scalar(0, 0, 0));

int main()
{

	/*int j1 = 0;
	int j2 = 0;
	int j3 = 0;

	for (double l = -1; l <= 1; l = l + .2) {
		for (double k = -1 * (.5*PI); k <= .5*PI; k = k + .00628) {
			for (double i = 0; i <= 2 * PI; i = i + .01256) {
				std::cout << i << " ,\t" << k << " ,\t" << l << " ,\t" << j1 << " ,\t" << j2 << " ,\t" << j3 << std::endl;
				j1 = j1 + 1;
			}
			j1 = 0;
			j2 = j2 + 1;
		}
		j2 = 0;
		j3 = j3 + 1;
	}*/

	unsigned int j1 = 0;
	unsigned int j2 = 0;
	int j3 = 0;
	double integral = 0;
	double integral2 = 0;
	
	for (double k = -1; k <= 1; k = k + .0040080160320641) {
		for (double i = 0; i <= 2 * PI; i = i + .01258) {
			if (j1 > 500 || j2 > 500) {
				std::cout << "ERROR: Out of bounds";
			}
			double vector11 = cos(i);
			double vector12 = sin(i);
			
			double vector21 = pow(k,4) - 1;
			double vector22 = k;


			double dist = sqrt(pow(vector11 - vector21, 2) + pow(vector12 - vector22, 2));

			double dArea = .01258*.004;
			double dVol = dArea*dist;

			double dTheta = .01258;
			double dArea2 = dTheta*dist;

			integral = integral + dVol;
			integral2 = integral2 + dArea2;

			double transform = (255 / 2)*dist;
			int transformCont = static_cast<int>(transform);

			cv::Mat sub(500, 500, CV_8UC3, cv::Scalar(transformCont, transformCont, transformCont));
			cv::Vec3b sub1 = sub.at<cv::Vec3b>(cv::Point(j2, j1));

			
			if (transformCont == 50) {
				::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
			}
			else if (transformCont == 100) {
				::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
			}
			else if (transformCont == 150) {
				::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
			}
			else if (transformCont == 200) {
				::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
			}
			else if (transformCont == 250) {
				::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
			}

			/*if (sqrt(pow(vector21,2) + pow(vector22, 2)) <= 1) {
				if (transformCont == 50) {
					::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
				}
				else if (transformCont == 100) {
					::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
				}
				else if (transformCont == 150) {
					::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
				}
				else if (transformCont == 200) {
					::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
				}
				else if (transformCont == 250) {
					::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;
				}
			}*/
			

			//::result.at<cv::Vec3b>(cv::Point(j2, j1)) = sub1;

			//std::cout << ::result.at<cv::Vec3b>(cv::Point(j2, j1));

			//std::cout << "(" << j1 << ", \t"<< j2 << ", \t"<< dist <<  ", \t" << transformCont << ", \t" << integral << " ,\t" << integral2 <<  ")"<< std::endl;

			j1 = j1 + 1;
		}
		//std::cin.get();
		std::cout << k << " ," << integral2 / (2 * PI) << std::endl;
		j1 = 0;
		j2 = j2 + 1;
		integral2 = 0;

	}


	

	cv::namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"

	cv::imshow("MyWindow", ::result); //display the image which is stored in the 'img' in the "MyWindow" window

	std::cout << ::result.at<cv::Vec3b>(cv::Point(10,10));
	std::cout << integral / (2 * PI);

	cv::waitKey(0); //wait infinite time for a keypress

	//std::cout << ::result;

	cv::destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
	//std::cin.get();

    return 0;
}

