// Copyrights Awie


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWIdgetController)
{
	WidgetController = InWIdgetController;
	WidgetControllerSet();
}


