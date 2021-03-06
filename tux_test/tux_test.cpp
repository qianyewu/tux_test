#include "pch.h"

//
//using namespace std;
//using namespace cv;
//COLORREF COLOR = RGB(255, 255, 255);
//void DDALine(int x0, int y0, int x1, int y1)
//{
//	//HWND myconsole = GetConsoleWindow();
//	//HDC mydc = GetDC(myconsole);
//	//COLORREF COLOR = RGB(255, 0, 0);
//	int dx, dy, epsl, k;
//	float x, y, xIncre, yIncre;
//	dx = x1 - x0;
//	dy = y1 - y0;
//	x = x0;
//	y = y0;
//	if (abs(dx) > abs(dy))
//		epsl = abs(dx);
//	else
//		epsl = abs(dy);
//	xIncre = (float)dx / (float)epsl;
//	yIncre = (float)dy / (float)epsl;
//	for (k = 0; k <= epsl; k++) {
//		//SetPixel(mydc, int(x + 0.5), int(y + 0.5), COLOR);
//		putpixel(int(x + 0.5), int(y + 0.5), COLOR);
//		x += xIncre;
//		y += yIncre;
//	}
//	//ReleaseDC(myconsole, mydc);
//	//cin.ignore();
//}
//
//void DDA(int x1, int y1, int x2, int y2)
//{
//	float x, y, xIncre, yIncre, length, i;
//	if (abs(x2 - x1) > abs(y2 - y1))
//		length = abs(x2 - x1);
//	else
//		length = abs(y2 - y1);
//	xIncre = (x2 - x1) / length;
//	yIncre = (y2 - y1) / length;
//	x = x1;
//	y = y1;
//	for (i = 0; i <= length; i++)
//	{
//		putpixel(int(x + 0.5), int(y + 0.5), COLOR);
//		x += xIncre;
//		y += yIncre;
//	}
//}
//
//void cd_line(int x1, int y1, int x2, int y2)
//{
//	int  dx, dy, n, k, f, i, x, y;
//	dx = abs(x2 - x1);
//	dy = abs(y2 - y1);
//	n = dx + dy;
//
//	if (x2 >= x1)
//	{
//		k = y2 >= y1 ? 1 : 4;
//		x = x1;
//		y = y1;
//	}
//	else
//	{
//		k = y2 >= y1 ? 2 : 3;
//		x = x1;
//		y = y1;
//	}
//	putpixel(x, y, COLOR);
//	for (i = 0, f = 0; i < n; i++)
//		if (f >= 0)
//			switch (k)
//			{
//			case 1:putpixel(x++, y, COLOR);
//				f -= dy;
//				break;
//			case 2:putpixel(x, y++, COLOR);
//				f -= dx;
//				break;
//			case 3:putpixel(x--, y, COLOR);
//				f -= dy;
//				break;
//			case 4:putpixel(x, y--, COLOR);
//				f -= dx;
//				break;
//			}
//		else switch (k)
//		{
//		case 1:putpixel(x, y++, COLOR);
//			f += dx;
//			break;
//		case 2:putpixel(x--, y, COLOR);
//			f += dy;
//			break;
//		case 3:putpixel(x, y--, COLOR);
//			f += dx;
//			break;
//		case 4:putpixel(x++, y--, COLOR);
//			f += dy;
//			break;
//		}
//}
//
//int sign(int  x)
//{
//	/*if (x < 0) return -1;
//	else if (x == 0)return 0;
//	else return 1;*/
//	return x < 0 ? -1 : x == 0 ? 0 : 1;
//}
//
//void Bresenham(int x1, int y1, int x2, int y2, int value = 0)
//{
//	int x, y, s1, s2, increx, increy, temp, interchange, e, i;
//	x = x1;
//	y = y1;
//	s1 = sign(x2 - x1);
//	s2 = sign(y2 - y1);
//	increx = abs(x2 - x1);
//	increy = abs(y2 - y1);
//	if (increy > increx)
//	{
//		temp = increx;
//		increx = increy;
//		increy = temp;
//		interchange = 1;
//	}
//	else
//		interchange = 0;
//	e = 2 * increy - increx;
//	for (i = 1; i <= increx; i++)
//	{
//		putpixel(x, y, COLOR);
//		if (e >= 0)
//		{
//			if (interchange = 1)
//				x = x + s1;
//			else
//				y = y + s2;
//			e = e - 2 * increx;
//		}
//		if (interchange = 1)
//			y = y + s2;
//		else
//			x = x + s1;
//		e = e + 2 * increy;
//	}
//}
//
//void Bresenham_1(int x0, int y0, int x1, int y1) {
//
//	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
//	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
//	int err = (dx > dy ? dx : -dy) / 2, e2;
//
//	for (;;) {
//		putpixel(x0, y0, COLOR);
//		if (x0 == x1 && y0 == y1) break;
//		e2 = err;
//		if (e2 > -dx) { err -= dy; x0 += sx; }
//		if (e2 < dy) { err += dx; y0 += sy; }
//	}
//}
//void rotateImage(Mat &img, Mat &img_rotate, int degree)
//{
//	//旋转中心为图像中心  
//	CvPoint2D32f center;
//	center.x = float(img.cols / 2.0 + 0.5);
//	center.y = float(img.rows / 2.0 + 0.5);
//	//计算二维旋转的仿射变换矩阵  
//	Mat M(2, 3, CV_32FC1);
//	M = getRotationMatrix2D(center, degree, 1);
//	clock_t t1 = clock();
//	//变换图像，并用黑色填充其余值  
//	warpAffine(img, img_rotate, M, img.size(), INTER_CUBIC);
//	clock_t t2 = clock();
//	cout << (t2 - t1)*1.0 / CLOCKS_PER_SEC / 10;
//}
//
//void FastRotateImage(Mat &srcImg, Mat &roateImg, float degree) {
//	assert((srcImg.cols > 0) && (srcImg.rows > 0));
//	float fsin, fcos, c1, c2, fx, fy, xx, yy;
//	int w1, h1, w, h;
//	w = srcImg.cols;
//	h = srcImg.rows;
//	int sz[2] = { srcImg.rows, srcImg.cols };
//	Mat map1_x, map2_y, m1, m2, m3, sPoint, newMap; //m1 m2 m3 为前文推荐博客中的基本矩阵
//	//1. 计算旋转参数
//	fsin = sin(degree);
//	fcos = cos(degree);
//	h1 = ceilf(abs(h*fcos) + abs(w*fsin));
//	w1 = ceilf(abs(w*fcos) + abs(h*fsin));
//	roateImg.create(h1, w1, CV_8UC1); //srcImg.type
//	map1_x.create(srcImg.size(), CV_32FC1);
//	map2_y.create(srcImg.size(), CV_32FC1);
//	c1 = (w - w1 * fcos - h1 * fsin) / 2;
//	c2 = (h + w1 * fsin - h1 * fcos) / 2;
//	//2. 计算前向的第一个点坐标
//	m1 = Mat::eye(3, 3, CV_32FC1);
//	m1.at<float>(2, 0) = -w / 2;
//	m1.at<float>(2, 1) = h / 2;
//	m1.at<float>(1, 1) = -1;
//	m2 = Mat::eye(3, 3, CV_32FC1);
//	m2.at<float>(0, 0) = fcos;
//	m2.at<float>(0, 1) = -fsin;
//	m2.at<float>(1, 0) = fsin;
//	m2.at<float>(1, 1) = fcos;
//	m3 = Mat::eye(3, 3, CV_32FC1);
//	m3.at<float>(2, 0) = w1 / 2;
//	m3.at<float>(2, 1) = h1 / 2;
//	m3.at<float>(1, 1) = -1;
//	sPoint = Mat::zeros(1, 3, CV_32FC1);
//	sPoint.at<float>(0, 2) = 1;
//	Mat snPoint = sPoint * m3*m2*m1;
//	//cout << snPoint << endl;
//	fx = snPoint.at<float>(0, 0) - fsin;
//	fy = snPoint.at<float>(0, 1) - fcos;
//	//3. 用直线画法计算剩余其他的映射点坐标
//	for (int y = 0; y < h; y++) {
//		//计算第一个前向映射点的精确位置
//		fx = fx + fsin;
//		fy = fy + fcos;
//		xx = fx - fcos;
//		yy = fy + fsin;
//		float *ptrx = map1_x.ptr<float>(y);
//		float *ptry = map2_y.ptr<float>(y);
//		for (int x = 0; x < w; x++) {
//			xx = xx + fcos;
//			yy = yy - fsin;
//			*(ptrx++) = xx;
//			*(ptry++) = yy;
//		}
//	}
//	//3.利用opencv的重映射函数完成前向映射的插值运算
//	remap(srcImg, roateImg, map1_x, map2_y, INTER_CUBIC, BORDER_CONSTANT, Scalar(0, 0, 0));
//}
//
//
//int main000()
//{
///*	int w, h,r, g, b;
//	w = 533;
//	h = 533;
//	initgraph(w, h);
//	loadimage(NULL, _T("t.bmp"));
//
//	// 获取默认绘图窗口的 HDC 句柄
//	HDC hdc;
//	 //hdc = GetImageHDC();
//	// 创建大小为 200x200 的 img 对象
//	IMAGE img(200, 200);
//
//	// 获取该 img 对象的 HDC 句柄
//	hdc = GetImageHDC(&img);
//	*/
//
//	Mat m = imread("F:\\C\\tux_test\\tux_test\\t.bmp",1);
//	Mat m1, gray_img;
//	cvtColor(m, gray_img, CV_RGB2GRAY);
//	rotateImage(gray_img,m1,30);
//	//FastRotateImage(gray_img, m1, 30.0);
//	imshow("gray_img", gray_img);
//	imshow("m1", m1);
//	
//	//cout << " t.bmp\n" << m << endl;
//	// 执行 Windows GDI 绘图函数
//	//Ellipse(hdc, 0, 50, 199, 150);
//
//	// 将 img 对象显示到绘图窗口上面
//	//putimage(100, 0, &img);
//
//	//cout<< typeid(initgraph(w, h)).name() << endl;
//
//
//	/*
//	int i, j;
//	for (i = 0; i < w; i++)
//		for (j = 0; j < h; j++)
//			//if (i % 2 == 0 && j % 2 != 0)
//				//putpixel(5, i,COLOR); WHITE
//				putpixel(j, i, WHITE);
//
//	*/
//
///*
//	DDALine(10, 10, 11, 333);
//	DDA(20, 10, 21, 333);
//	cd_line(30, 10, 31, 333);
//	Bresenham(40, 10, 41, 333);
//	Bresenham(50, 10, 51, 333);
//	line(60, 10, 61, 333);
//	circle(250,153,23);
//	circle(250, 153, 83);
//	circle(250, 153, 3);
//	*/
//
//	
//		//DDALine(10, 10, 233, 333);
//	//	DDA(10, 20, 233, 343);
//	//	cd_line(10, 30, 233, 353);
//	//	Bresenham(10, 40, 233, 363);
//	//	line(10,50, 233, 373);
//	
//	
//	//saveimage(_T("t.bmp"));
//	waitKey();
//	getchar();
//	//closegraph();
//	system("pause");
//	return 0;
//}
//
///*
//int main()
//{
//	int w, h;
//	w = 533;
//	h = 533;
//	initgraph(w, h);
//	int a, c,p;
//	a = 1;
//	c = 255;
//	srand((unsigned)time(NULL));
//	int r, g, b;
//	r = 20;
//	g = 214;
//	b = 98;
//
//	for (int i = 0; i < 5233; i++)
//	{
//		r = (rand() % (c - a + 1)) + a;
//		g = (rand() % (c - a + 1)) + a;
//		b = (rand() % (c - a + 1)) + a;
//		COLORREF col = RGB(r, g, b);
//		putpixel((rand() % h ) , (rand() % h), col);
//		//cout << p<<" ";
//	}
//
//
//	//saveimage(_T("t.bmp"));
//	getchar();
//	closegraph();
//	cout << "Hello World!\n";
//	system("pause");
//}
//*/
