#pragma once

#ifdef VS_PLATFORM_WINDOWS

extern Visionizer::Application* Visionizer::CreateApplication();

int main(int argc, char** argv)
{
	Visionizer::Log::Init();
	VS_CORE_TRACE("Initializing the Core...");
	VS_CORE_INFO("Initialized Log!");

	auto app = Visionizer::CreateApplication();
	VS_CORE_TRACE("Core initialized");
	VS_CORE_ASSERT(app, "App not found");
	VS_INFO("Welcome to Visionizer!");
	app->Run();
	delete app;
}

#endif