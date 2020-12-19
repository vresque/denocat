#pragma once

#ifdef  VS_PLATFORM_WINDOWS

extern Visionizer::Application* Visionizer::CreateApplication();

int main(int argc, char** argv)
{
	Visionizer::Log::Init();
	VS_CORE_WARN("Initialized Log!");
	int a = 5;
	VS_INFO("Hello! Var={0}", a);

	auto app = Visionizer::CreateApplication();
	app->Run();
	delete app;
}

#endif