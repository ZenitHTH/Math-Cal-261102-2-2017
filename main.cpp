#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <math.h>
#include <cstdlib>
#include <cstdio>
    HWND text_tri;
    HWND button;
    char textsave_tri[128] ;



/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = GetSysColorBrush(COLOR_3DFACE);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Math-Calculator"),       /* Title Text */
           WS_VISIBLE | WS_MAXIMIZE, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           640,                 /* The programs width */
           480,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{


    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:

        CreateWindow("STATIC",
                     "Calculator",
                     WS_VISIBLE | WS_CHILD,
                     280,20,70,40,
                     hwnd,NULL,NULL,NULL);

        CreateWindow("STATIC",
                     "Trigonometry",
                     WS_VISIBLE | WS_CHILD,
                     100,40,120,20,
                     hwnd,NULL,NULL,NULL);

        button = CreateWindow("BUTTON",
                                "EXIT",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                300,400,50,20,
                                hwnd,(HMENU) 100,NULL,NULL);

        text_tri = CreateWindow("EDIT",
                                "",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                90,70,100,20,
                                hwnd,NULL,NULL,NULL);

        button = CreateWindow("BUTTON",
                                "Cos",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                40,95,60,20,
                                hwnd,(HMENU) 1,NULL,NULL);



        button = CreateWindow("BUTTON",
                                "Sin",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                110,95,60,20,
                                hwnd,(HMENU) 2,NULL,NULL);


        button = CreateWindow("BUTTON",
                                "Tan",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                180,95,60,20,
                                hwnd,(HMENU) 3,NULL,NULL);


        button = CreateWindow("BUTTON",
                              "Cosec",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,120,60,20,
                              hwnd,(HMENU) 4,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sec",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,120,60,20,
                              hwnd,(HMENU) 5,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Cot",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,120,60,20,
                              hwnd,(HMENU) 6,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sin^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,145,60,20,
                              hwnd,(HMENU) 7,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Cos^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,145,60,20,
                              hwnd,(HMENU) 8,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Tan^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,145,60,20,
                              hwnd,(HMENU) 9,NULL,NULL);





        break;

        case WM_COMMAND:

            if(LOWORD(wParam) == 100)
            {
                PostQuitMessage (0);
            }
            else
            if(LOWORD(wParam) == 1)
            {
                float coos,ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                coos = atof(textsave_tri);
                ans = cos(coos*3.14159265/180);

                sprintf(ptr,"%f",ans);

                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }else
            if(LOWORD(wParam) == 2)
            {
                float siin,ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                siin = atof(textsave_tri);
                ans = sin(siin*3.14159265/180);

                sprintf(ptr,"%f",ans);

                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }else
            if(LOWORD(wParam) == 3)
            {
                float taan,ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                taan = atof(textsave_tri);
                ans = tan(taan*3.14159265/180);

                sprintf(ptr,"%f",ans);

                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }




        break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
