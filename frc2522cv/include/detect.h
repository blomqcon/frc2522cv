#ifndef DETECT_H
#define DETECT_H

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>


namespace frc2522cv {

	class Target {
        public:
            Target();
            int cameraWidth;
            int cameraHeight;
            std::vector<cv::Point3i> zeroPoints;

            cv::Point3i getCenter();

            //Checks relative size and aspect ratios to determine where you must be
            //Assumes foundTarget is the target.
            cv::Point3i location(Target foundTarget);
	};

    namespace detect {
		enum Type {SimpleBlob, Blob, Contour, HoughLine};

		cv::Point2f targetScreenLocation(cv::Mat image, Target target, Type type);
		cv::Mat showScreenLocation(cv::Mat image, Target target, Type type);

		cv::Point3f cameraLocation();
		double robotAngle();
    }
}



#endif // DETECT_H
