#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include "Cal.h"
    HWND text_tri;
    HWND text_log;
    HWND text_pow_1,text_pow_2;
    HWND button;
    char textsave_tri[128] ;
    char textsave_log[128] ;
    char textsave_pow_1[64],textsave_pow_2[64] ;



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
           800,                 /* The programs width */
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
                     380,20,70,40,
                     hwnd,NULL,NULL,NULL);

        //Trigonmetry
        //1.Cos 2.Sin 3.Tan 4.Cosec 5. Sec 6.Cot 7.arc-sin 8.arc-cos 9.arc-tan


        CreateWindow("STATIC",
                     "Trigonometry and Hyperbolic",
                     WS_VISIBLE | WS_CHILD,
                     45,40,200,20,
                     hwnd,NULL,NULL,NULL);

        button = CreateWindow("BUTTON",
                                "EXIT",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                400,400,50,20,
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

        button = CreateWindow("BUTTON",
                              "CSC^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,170,60,20,
                              hwnd,(HMENU) 10,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sec^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,170,60,20,
                              hwnd,(HMENU) 11,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Cot^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,170,60,20,
                              hwnd,(HMENU) 12,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sinh",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,195,60,20,
                              hwnd,(HMENU) 13,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Cosh",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,195,60,20,
                              hwnd,(HMENU) 14,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Tanh",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,195,60,20,
                              hwnd,(HMENU) 15,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "CSCh",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,220,60,20,
                              hwnd,(HMENU) 16,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sech",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,220,60,20,
                              hwnd,(HMENU) 17,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Coth",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,220,60,20,
                              hwnd,(HMENU) 18,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sinh^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,245,60,20,
                              hwnd,(HMENU) 19,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Cosh^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,245,60,20,
                              hwnd,(HMENU) 20,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Tanh^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,245,60,20,
                              hwnd,(HMENU) 21,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "CSCh^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,270,60,20,
                              hwnd,(HMENU) 22,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Sech^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,270,60,20,
                              hwnd,(HMENU) 13,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Coth^(-1)",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,270,60,20,
                              hwnd,(HMENU) 24,NULL,NULL);




        // log exp ln
        //31.ln (ln's command is log) 32.log (log's command is log10) 33.exp (Exponential)

                    CreateWindow("STATIC",
                                 "Exponential and Logarithmic",
                                 WS_VISIBLE | WS_CHILD,
                                 50,290+10,200,20,
                                 hwnd,NULL,NULL,NULL);

        text_log = CreateWindow("EDIT",
                                "",
                                WS_VISIBLE | WS_CHILD | WS_BORDER ,
                                90,320+10,100,20,
                                hwnd,NULL,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "ln",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              40,350+10,60,20,
                              hwnd,(HMENU) 31,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "log",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              110,350+10,60,20,
                              hwnd,(HMENU) 32,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "exp",
                              WS_VISIBLE | WS_CHILD | WS_BORDER,
                              180,350+10,60,20,
                              hwnd,(HMENU) 33,NULL,NULL);

        //Pow and nth root
        //41.Pow 42.nth root (use number^1/n)

        CreateWindow("STATIC",
                     "Power and nth Root",
                     WS_VISIBLE | WS_CHILD ,
                     320,40,150,20,
                     hwnd,NULL,NULL,NULL);

        text_pow_1 = CreateWindow("EDIT",
                                "",
                                WS_VISIBLE | WS_CHILD | WS_BORDER ,
                                390,70,70,20,
                                hwnd,NULL,NULL,NULL);

        text_pow_2 = CreateWindow("EDIT",
                                  "",
                                  WS_VISIBLE | WS_CHILD | WS_BORDER ,
                                  390,95,70,20,
                                  hwnd,NULL,NULL,NULL);

        CreateWindow("STATIC",
                     "Number",
                     WS_VISIBLE | WS_CHILD ,
                     300,70,50,20,
                     hwnd,NULL,NULL,NULL);

        CreateWindow("STATIC",
                     "Pow / Root",
                     WS_VISIBLE | WS_CHILD ,
                     300,95,70,20,
                     hwnd,NULL,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Power",
                               WS_VISIBLE | WS_CHILD | WS_BORDER ,
                               320,120,60,20,
                               hwnd,(HMENU) 41,NULL,NULL);

        button = CreateWindow("BUTTON",
                              "Root",
                               WS_VISIBLE | WS_CHILD | WS_BORDER ,
                               390,120,60,20,
                               hwnd,(HMENU) 42,NULL,NULL);



        // what's next?



        break;

        case WM_COMMAND:

            if(LOWORD(wParam) == 100)
            {
                PostQuitMessage (0);
            }
            else
            if(LOWORD(wParam) == 1)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = COS(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }else
            if(LOWORD(wParam) == 2)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = SIN(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }else
            if(LOWORD(wParam) == 3)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = TAN(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }else
            if(LOWORD(wParam) == 4)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = COSEC(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd, ptr ,"Result",MB_OK);

            }else
            if(LOWORD(wParam) == 5)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = SEC(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 6)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = COT(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 7)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = ASIN(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 8)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = ACOS(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 9)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = ATAN(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 10)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = ACOSEC(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 11)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = ASEC(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 12)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_tri,&textsave_tri[0],64);
                ans = ACOT(textsave_tri);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else




            if(LOWORD(wParam) == 31)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_log,&textsave_log[0],64);
                ans = Ln(textsave_log);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 32)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_log,&textsave_log[0],64);
                ans = LOG(textsave_log);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 33)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_log,&textsave_log[0],64);
                ans = EXPO(textsave_log);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 41)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_pow_1,&textsave_pow_1[0],64);
                GetWindowText(text_pow_2,&textsave_pow_2[0],64);
                ans = POW(textsave_pow_1,textsave_pow_2);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
            }else
            if(LOWORD(wParam) == 42)
            {
                float ans;
                char ptr[0];
                GetWindowText(text_pow_1,&textsave_pow_1[0],64);
                GetWindowText(text_pow_2,&textsave_pow_2[0],64);
                ans = SQRT(textsave_pow_1,textsave_pow_2);
                sprintf(ptr,"%f",ans);
                ::MessageBox(hwnd,ptr,"Result",MB_OK);
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
