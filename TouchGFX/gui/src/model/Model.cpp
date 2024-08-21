#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

// A queue to send the data from a task to GUI
extern "C" {
	osMessageQueueId_t mid_MODELMsgQueue;                // message queue
}
DHT22_DataTypedef modelDHT22_Data;

Model::Model() : modelListener(0)
{
	// create a message queue:
	mid_MODELMsgQueue = osMessageQueueNew(5, sizeof(DHT22_DataTypedef), NULL);
	if (mid_MODELMsgQueue == NULL) {
		// Message Queue object not created, handle failure
	}
}

void Model::tick()
{
	// check if a new message has arrived - do not wait for it, just check :
	if (osMessageQueueGet(mid_MODELMsgQueue, &modelDHT22_Data, NULL, 0U) == osOK)   // check for message
	{
		// forward data to listener (first to presenter then view)
		modelListener->updateTempData(&modelDHT22_Data);
	}
}
