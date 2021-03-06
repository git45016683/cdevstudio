#ifndef PLUGINPAGE_H
#define PLUGINPAGE_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGridLayout>
#include <cdevstudioplatform/SettingsPage.h>

#include "PluginTextEditorExport.h"

class PLUGINTEXTEDITOR_EXPORT PluginPage : public SettingsPage
{
	Q_OBJECT
	
public:
	PluginPage(QWidget *parent);
	QString getName();
};

#endif // PLUGINPAGE_H
