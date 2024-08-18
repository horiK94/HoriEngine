#pragma once
#include <memory>

namespace HoriEngine
{
	class Window
	{
	public:
		Window();
		~Window();

		bool init();
		bool update();
	private:
		class Impl;
		std::shared_ptr<Impl> m_pImpl;
	};
}
