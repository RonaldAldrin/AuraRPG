// Copyrights Awie


#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"


void UAuraUserWidget::SetWidgetController(UObject* InWIdgetController)
{
	WidgetController = InWIdgetController;
	WidgetControllerSet();

	

}
