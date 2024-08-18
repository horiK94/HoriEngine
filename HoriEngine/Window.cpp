#include "Window.hpp"
#include <Windows.h>

namespace HoriEngine
{
	class Window::Impl
	{
	public:
		bool init();
		bool update();

		~Impl();
	private:
		HWND m_hWnd = nullptr;		//ウィンドウハンドル.1つのウィンドウに対して1つのハンドルが割り当てられる
		HMODULE m_moduleHandle = nullptr;	//=hInstace. 1つモジュール(実行ファイル)に対して1つのハンドルが割り当てられる. WinMain関数の第1引数として渡されるが関数でも取れる

	};

	const wchar_t* window_class_name = L"HoriEngine";	//ウィンドウクラス名

	LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)		//ウィンドウからのメッセージを処理する
	{
		switch (msg)
		{
		case WM_DESTROY:	//ウィンドウが破棄されたとき
			::PostQuitMessage(0);	//メッセージキューにWM_QUITメッセージを送る
			break;
		}

		return ::DefWindowProcW(hWnd, msg, wParam, lParam);	//デフォルトのウィンドウプロシージャを呼び出す

	}

	bool Window::Impl::init()
	{
		m_moduleHandle = ::GetModuleHandleW(nullptr);	//現在のモジュールのハンドルを取得

		//ウィンドウスタイルを定義したクラスを作る
		WNDCLASSEX windowClass
		{
			.cbSize = sizeof(WNDCLASSEX),	//構造体のサイズ
			.style = CS_HREDRAW | CS_VREDRAW,	//ウィンドウクラスのスタイル
			.lpfnWndProc = WindowProc,	//ウィンドウプロシージャのアドレス. これだけだと実行されない
			.hInstance = m_moduleHandle,	//ウィンドウプロシージャが属するモジュールのハンドル
			.hIcon = nullptr,	//実行中ウィンドウのアイコン(左上)のハンドル = なし
			.hCursor = nullptr,	//カーソルのハンドル = なし
			.hbrBackground = static_cast<HBRUSH>(::GetStockObject(DKGRAY_BRUSH)),	//ウィンドウの背景色 (DirectXだと上書きされるのでほぼ無意味)
			.lpszClassName = window_class_name,	//ウィンドウクラスを登録するのに使う. 同じインスタンスでユニークな名前?
		};

		if (not ::RegisterClassExW(&windowClass))
		{
			return false;
		}

		//ウィンドウ作成
		m_hWnd = ::CreateWindowExW(
			0,	//拡張ウィンドウスタイル
			window_class_name,	//ウィンドウクラス名
			L"HoriEngine",	//ウィンドウタイトル
			WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME),	//ウィンドウスタイル
			CW_USEDEFAULT,	//ウィンドウのX座標
			CW_USEDEFAULT,	//ウィンドウのY座標
			CW_USEDEFAULT,	//ウィンドウの幅
			CW_USEDEFAULT,	//ウィンドウの高さ
			nullptr,	//親ウィンドウのハンドル
			nullptr,	//メニューハンドル
			m_moduleHandle,	//インスタンスハンドル
			nullptr		//追加パラメータ
		);

		if (m_hWnd == nullptr)
		{
			return false;
		}

		//ウィンドウ表示
		::ShowWindow(
			m_hWnd,
			SW_SHOW	//どういう表示の仕方をしたいか？ SW_SHOW = 通常の表示, 最大表示etc..。 他のプログラムからWinMain()の引数で指定されるので、それに従ってもOK 
		);

		return true;
	}

	bool Window::Impl::update()
	{
		MSG msg;
		while (::PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE))	//メッセージキューからメッセージを取り出す
		{
			// ウィンドウメッセージあり
			if (msg.message == WM_QUIT)
			{
				OutputDebugStringW(L"Quit in update()\n");
				return false;
			}

			::TranslateMessage(&msg);	//キーボードメッセージを文字メッセージに変換
			::DispatchMessageW(&msg);	//メッセージをウィンドウプロシージャに送る
		}

		return true;
	}


	Window::Impl::~Impl()
	{
		OutputDebugStringW(L"~Impl()\n");
		::UnregisterClassW(window_class_name, m_moduleHandle);	//ウィンドウクラスを登録解除


	}

	///pimplの初期化
	Window::Window() : m_pImpl(std::make_shared<Impl>())
	{
	}

	Window::~Window()
	{
	}

	bool Window::init()
	{
		return m_pImpl->init();
	}

	bool Window::update()
	{
		return m_pImpl->update();
	}
}
