#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include "Emoji01.h"
#include "Emoji02.h"
#include "Emoji03.h"
#include "Emoji04.h"
#include "Emoji05.h"

// Global Variables:
HINSTANCE hInst;					// current instance
TCHAR szTitle[]="L9";				// The title bar text
TCHAR szWindowClass[]="WinApp";				// the class name




// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;

	// Register Class 
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. 
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon (NULL, IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
//	wcex.lpszMenuName	= NULL;
	wcex.lpszMenuName  = MAKEINTRESOURCE(IDR_MYMENU);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon (NULL, IDI_APPLICATION);
//   	wcex.hIcon  = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
//    wcex.hIconSm  = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

	return RegisterClassEx(&wcex);
}
//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
WPARAM EMOJI1(HDC hdc,HWND hWnd)
{   

	Emoji01::MyEmoji01::Draw(hWnd);

	return 0;
	
}

WPARAM EMOJI2(HDC hdc,HWND hWnd)
{   Emoji02::MyEmoji02::Draw(hWnd);

	return 0;	
}

WPARAM  EMOJI3(HDC hdc,HWND hWnd)
{   
	Emoji03::MyEmoji03::Draw(hWnd);

	return 0;

		
}


WPARAM EMOJI4(HDC hdc,HWND hWnd)
{   	Emoji04::MyEmoji04::Draw(hWnd);

	return 0;
		
}

WPARAM  EMOJI5(HDC hdc,HWND hWnd)
{    
			Emoji05::MyEmoji05::Draw(hWnd);

	return 0;		      
					       
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rt;
	char szHello[]="Hello, C-Free!";
	
	switch (message) 
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			
			GetClientRect(hWnd, &rt);
			//Ellipse (hdc, 10, 10, 200, 100);

			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			
			EndPaint(hWnd, &ps);
			break;
        case WM_COMMAND:
            switch(LOWORD(wParam))
            {
                case ID_FILE_SAVE:
	                break;
                case ID_FILE_EXIT:
				 SendMessage(hWnd,WM_CLOSE,0,0);	
	                break;
                case ID_PIC_EMO1:
                   hdc = GetDC(hWnd);
                   SendMessage(hWnd,WM_PAINT,EMOJI1(hdc,hWnd),NULL);
                   

					 ReleaseDC(hWnd,hdc);
					 
					 
					 break;
					 case ID_PIC_EMO2:
                     hdc = GetDC(hWnd);
					 SendMessage(hWnd,WM_PAINT,EMOJI2(hdc,hWnd),NULL); 
			         ReleaseDC(hWnd,hdc);
                  
	                break;
	                
	                case ID_PIC_EMO3:
                      hdc = GetDC(hWnd);
					 SendMessage(hWnd,WM_PAINT,EMOJI3(hdc,hWnd),NULL); 
			         ReleaseDC(hWnd,hdc);
                     
	                break;
	                
	                case ID_PIC_EMO4:
                      hdc = GetDC(hWnd);
					 SendMessage(hWnd,WM_PAINT,EMOJI4(hdc,hWnd),NULL); 
			         ReleaseDC(hWnd,hdc);

	                break;
	                
	                  case ID_PIC_EMO5:
                      hdc = GetDC(hWnd);
					 SendMessage(hWnd,WM_PAINT,EMOJI5(hdc,hWnd),NULL); 
			         ReleaseDC(hWnd,hdc);

	                break;
	                

	               
            }
        break;
        
        
        case WM_LBUTTONDOWN: 
		InvalidateRect(hWnd, NULL, TRUE);
    		return 0L; 
    
    return 0L; 
 
  
   case WM_LBUTTONUP: 
   	InvalidateRect(hWnd, NULL, TRUE);
    		return 0L; 

		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
