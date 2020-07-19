//headers
#include<windows.h>
#pragma comment (lib,"gdi32.lib")
#pragma comment (lib,"user32.lib")
//global func declaration
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//winmain
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpszCmdLine,int iCmdShow)
{
	//VARIABLE DECLARATIONS
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[]=TEXT("MyApp");

	//code
	//installation of wndclassex
	wndclass.cbSize=sizeof(WNDCLASSEX);
	wndclass.style=CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.lpfnWndProc=WndProc;
	wndclass.hInstance= hInstance;
	wndclass.hIcon= LoadIcon(NULL,IDI_APPLICATION);
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName =szAppName;
	wndclass.lpszMenuName=NULL;
	wndclass.hIconSm =LoadIcon(NULL,IDI_APPLICATION);

	//register above classs
	RegisterClassEx(&wndclass);

	//create window
	hwnd=CreateWindow(szAppName,
		TEXT("My Application"),
		
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd,iCmdShow);
	UpdateWindow(hwnd);
	
	//message loop
	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);

}
LRESULT CALLBACK WndProc(HWND hwnd ,UINT iMsg,WPARAM wParam,LPARAM lParam)
{

	//code
	switch(iMsg)
	{
	case WM_DESTROY:
	PostQuitMessage(0);
	break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lParam));
}
