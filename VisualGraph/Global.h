// Global.h
#pragma once

#include <functional>

class QWidget;
class VisualGraph;

extern const char g_applicationName[];
extern VisualGraph* g_mainWindow;

void RunGuiAction(QWidget* widget, std::function<void()> func);
