#include "ofApp.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/local_time_adjustor.hpp"
#include "boost/date_time/c_local_time_adjustor.hpp"


int main()
{

    ofSetupOpenGL(800, 700, OF_WINDOW);
    ofRunApp(new ofApp());
}
