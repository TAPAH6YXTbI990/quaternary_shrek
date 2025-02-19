#include <opencv2/opencv.hpp>
#include <iostream>
#include <locale>
#include <codecvt>

using namespace cv;

int main()
{
    std::system("chcp 65001 > nul");

    std::string image_path = "C:/Users/User/.vscode/projects/OpenShrek.jpg"; 
   
    Mat img = imread(image_path);

    if (img.empty())
    {
        std::cerr << "Îøèáêà ïðè çàãðóçêå èçîáðàæåíèÿ!" << std::endl;
        return -1; 
    }

    Mat result = img.clone(); 

    int width = img.cols / 2;
    int height = img.rows / 2;

    Mat mask1 = result(Rect(0, 0, width, height)); 
    Mat mask2 = result(Rect(0, height, width, height));  
    Mat mask3 = result(Rect(width, 0, width, height)); 
    Mat mask4 = result(Rect(width, height, width, height)); 

    Mat gray;
    cvtColor(mask2, gray, COLOR_BGR2GRAY); 
    cvtColor(gray, gray, COLOR_GRAY2BGR);
    gray.copyTo(mask2);
    
    bitwise_not(mask3,mask3);   
    
    mask4.setTo(Scalar(100,5,255));

    imshow("Èñõîäíîå èçîáðàæåíèå", img);
    imshow("Ðåçóëüòàò", result);

    int k = waitKey(0); 

    return 0;
}
