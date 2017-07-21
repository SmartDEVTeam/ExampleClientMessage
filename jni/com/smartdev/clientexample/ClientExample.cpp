#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/client/MinecraftGame.h"
#include "com/mojang/minecraftpe/client/gui/GuiData.h"

static void (*_MinecraftGame$onPlayerLoaded)(MinecraftGame*, Player&);
static void MinecraftGame$onPlayerLoaded(MinecraftGame* self, Player& player)
{
	_MinecraftGame$onPlayerLoaded(self, player);

	self->getGuiData()->displayClientMessage("Custom Example Client Message!");
}


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	
	MSHookFunction((void*) &MinecraftGame::onPlayerLoaded, (void*) &MinecraftGame$onPlayerLoaded, (void**) &_MinecraftGame$onPlayerLoaded);
	
	return JNI_VERSION_1_2;
}
