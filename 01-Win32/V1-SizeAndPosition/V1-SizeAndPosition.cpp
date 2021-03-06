//headers
#include<windows.h>

//global function declaration
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//WINMAIN
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevinstance,LPSTR lpszCmdLine,int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;//struct for custom window
	HWND hwnd;//""
	MSG msg;//""
	TCHAR szAppName[]=TEXT("MyApp");//text is macro name goes to os n we cant see it
	bool fResult;
	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize=sizeof(WNDCLASSEX);
	wndclass.style=CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra=0;
	wndclass.cbWndExtra=0;
	wndclass.lpfnWndProc= WndProc;
	wndclass.hInstance=hInstance;
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);//first parameter is hInstance
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName=szAppName;
	wndclass.lpszMenuName=NULL;
	wndclass.hIconSm=LoadIcon(NULL,IDI_APPLICATION);

	//REGISTER ABOVE CLASS
	RegisterClassEx(&wndclass);

	//create window
	//wndclass.lpszClassName=szAppName;
	hwnd=CreateWindow(szAppName,
		TEXT("MY APPLICATION"),
		WS_OVERLAPPEDWINDOW,
		(GetSystemMetrics(SM_CXSCREEN)/2-400),
		(GetSystemMetrics(SM_CYSCREEN)/2-300),
		800,
		600,
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
LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lparam)
{
	//code
	switch(iMsg)
	{
	case WM_DESTROY:
			PostQuitMessage(0);
			break;
	}
	return(DefWindowProc(hwnd,iMsg,wParam,lparam));
}