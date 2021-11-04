#include "SIMPLESOCKET.H"
#include <string>
#include "TASK3.H"
#include <vector>
#include <sstream>

class myServer : public TCPserver{
public:
	myServer(int port, int maxDataSizeRecv) : TCPserver( port,maxDataSizeRecv){};


protected:

	 string myResponse(string input);

private:
	 TASK3::World w;
	 int x,y;
	 TASK3::ShootResult res;

	 vector<int> convKord(string input);



};
