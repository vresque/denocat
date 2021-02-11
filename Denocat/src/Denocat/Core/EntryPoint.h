#pragma once

#ifdef  VS_PLATFORM_WINDOWS

extern Denocat::Application* Denocat::CreateApplication();

int main(int argc, char** argv)
{
	Denocat::Log::Init();
	VS_CORE_WARN("Initialized Log!");
	int a = 5;
	VS_INFO("Hello! Var={0}", a);

	auto app = Denocat::CreateApplication();
	app->Run();
	delete app;
}

#endif