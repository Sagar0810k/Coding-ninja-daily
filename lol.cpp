// ============================================================
// Simple Login GUI Template (Win32 API, no external libraries)
// ============================================================
// Compile (MinGW):  g++ lol.cpp -o lol -mwindows
// ============================================================

#include <windows.h>
#include <string>

// Control IDs
#define ID_EDIT_USERNAME 101
#define ID_EDIT_PASSWORD 102
#define ID_BUTTON_LOGIN  103
#define ID_BUTTON_CLEAR  104
#define ID_STATIC_STATUS 105

// Hardcoded demo credentials (replace with real auth logic)
const std::string VALID_USERNAME = "admin";
const std::string VALID_PASSWORD = "password123";

HWND hEditUser, hEditPass, hStatus;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE: {
            CreateWindowA("STATIC", "Username:", WS_VISIBLE | WS_CHILD,
                20, 30, 80, 20, hwnd, NULL, NULL, NULL);

            hEditUser = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER,
                110, 28, 180, 24, hwnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);

            CreateWindowA("STATIC", "Password:", WS_VISIBLE | WS_CHILD,
                20, 70, 80, 20, hwnd, NULL, NULL, NULL);

            hEditPass = CreateWindowA("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD,
                110, 68, 180, 24, hwnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);

            CreateWindowA("BUTTON", "Login", WS_VISIBLE | WS_CHILD,
                40, 110, 90, 30, hwnd, (HMENU)ID_BUTTON_LOGIN, NULL, NULL);

            CreateWindowA("BUTTON", "Clear", WS_VISIBLE | WS_CHILD,
                160, 110, 90, 30, hwnd, (HMENU)ID_BUTTON_CLEAR, NULL, NULL);

            hStatus = CreateWindowA("STATIC", "", WS_VISIBLE | WS_CHILD,
                20, 155, 270, 40, hwnd, (HMENU)ID_STATIC_STATUS, NULL, NULL);
            break;
        }

        case WM_COMMAND: {
            switch (LOWORD(wParam)) {
                case ID_BUTTON_LOGIN: {
                    char userBuf[256], passBuf[256];
                    GetWindowTextA(hEditUser, userBuf, 256);
                    GetWindowTextA(hEditPass, passBuf, 256);

                    std::string user(userBuf);
                    std::string pass(passBuf);

                    if (user.empty() || pass.empty()) {
                        SetWindowTextA(hStatus, "Please fill in both fields.");
                    } else if (user == VALID_USERNAME && pass == VALID_PASSWORD) {
                        SetWindowTextA(hStatus, "Login successful!");
                    } else {
                        SetWindowTextA(hStatus, "Invalid username or password.");
                    }
                    break;
                }

                case ID_BUTTON_CLEAR: {
                    SetWindowTextA(hEditUser, "");
                    SetWindowTextA(hEditPass, "");
                    SetWindowTextA(hStatus, "");
                    break;
                }
            }
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "LoginWindowClass";

    WNDCLASSA wc = {};
    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(
        0, CLASS_NAME, "Login",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 330, 240,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}