This app will join your Zoom Video SDK session, display videos from all users and detect "banana" from the video. This app is to demostrate using of Zoom Video SDK's Raw Data. It uses OpenCV to detect object. 

## Generate You JWT
You much have an account [subscribed](https://marketplace.zoom.us/docs/sdk/video/developer-accounts/) Zoom Video SDK. 

Find your Video SDK [key and secret](https://marketplace.zoom.us/docs/sdk/video/auth/#get-video-sdk-key-and-secret). 

Generate your JWT with [this script](https://gist.github.com/linanw/9144d9bfc84da4076ab5beb04d4f9db1).

## Dependencies
### Tools
```
sudo apt update
sudo apt install -y unzip wget
```

### install OpenCV
```
wget -O opencv.4.6.0.zip https://codeload.github.com/opencv/opencv/zip/refs/tags/4.6.0  
unzip opencv.4.6.0.zip
cd opencv.4.6.0
cmake -B build
cd build
make -j20
sudo make install
```

### install GL
```
sudo apt install -y libgl1-mesa-dev
```

## Run 
Open and build the code with Qt Creator. 

Copy the banana_classifier.xml to the running folder. 

Start the app from Qt Creator.

