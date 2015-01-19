#define NON_MATLAB_PARSING
#define MAX_EXT_API_CONNECTIONS 255


//To make this thing work with your Vrep project
//Go to "Script" and edit main script
//Find :
//  if (sim_call_type==sim_mainscriptcall_initialization) then
//At end of this block add :
//  simExtRemoteApiStart(4242)
//Find
//  if (sim_call_type==sim_mainscriptcall_cleanup) then
//At end of this block add
//  simExtRemoteApiStop(4242)

#include "vrep-api/extApi.h"
#include "vrep-api/extApiPlatform.h"
#include <iostream> 



int main(int argc, char const *argv[])
{
	int vrep;
	while(vrep < 0)
	{
		std::cout << "Waiting for simulation starting" << std::cin;
		vrep = simxStart("127.0.0.1", 4242, true, false, 1000, 5);
	}

	return 0;
}

