* # Adapter Selection sample

This is a desktop application that demonstrates how to enumerate and select device adapters to run onnx models on using Windows Machine Learning using DxCore. This sample is set up to run a SqueezeNet image detection model on the selected device.

Note: SqueezeNet was trained to work with image sizes of 224x224, so you must provide an image of size 224X224.

## Prerequisites

- [Visual Studio 2019 Release Candidate](https://devblogs.microsoft.com/visualstudio/visual-studio-2019-release-candidate-rc-now-available/)
- Windows MCDM VHD 18342 \\\grfxshare\Sigma-GRFX\MCDM\18342-sample-development\mcdm-18342.vhd
- Windows SDK - Build 18342 \\\grfxshare\Sigma-GRFX\MCDM\18342-sample-development\windowssdk
- Visual Studio Extension for C++/WinRT

  Do the following to add the C++/WinRT extension in Visual Studio.
  1. Go to **Tools > Extensions and Updates**. 
  2. Select **Online** in the left pane and search for "WinRT" using the search box.
  3. Select the **C++/WinRT** extension, click **Download**, and close Visual Studio. The extension should install automatically.
  4. When the extension has finished installing, re-open Visual Studio.

## Build the sample

DXCore is not part of the 19H1 SDK; until the 19H2 SDKs are available, you must manually add back the files:

>\\\grfxshare\Sigma-GRFX\MCDM\18342-sample-development\dxcore-sdk

Copy this file | Into this folder
| ------------- |:-------------|
dxcore.h |	C:\Program Files (x86)\Windows Kits\10\Include\10.0.18342.0\um
dxcore_interface.h |	C:\Program Files (x86)\Windows Kits\10\Include\10.0.18342.0\um
dxcore.lib |	C:\Program Files (x86)\Windows Kits\10\Lib\10.0.18342.0\um\x64


## Run the sample
Usage:
```
SqueezeNetObjectDetection_MCDM_AdapterSelection.exe [options]
options:
  -Model <full path to model>: Model Path (Only FP16 models)
  -Image <full path to image>: Image Path
  -SelectAdapter : Toggle select adapter functionality to select the device to run sample on.
```


1. Open a Command Prompt (in the Windows 10 search bar, type **cmd** and press **Enter**).
2. Change the current folder to the folder containing the built EXE (`cd <path-to-exe>`).
3. Run the executable as shown below. Make sure to replace the install location with what matches yours:
  ```
  SqueezeNetObjectDetection_MCDM_AdapterSelection.exe
  ```
You should get output similar to the following:
  ```
  Index: 0, Description: Intel(R) Iris(R) Plus Graphics 650
  Index: 2, Description: Intel(R) VPU Aceelerator 2485
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Successfully created LearningModelDevice with selected Adapter
Loading modelfile '.\SqueezeNet_fp16.onnx' on the selected device
model file loaded in 16 ticks
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Movidius Compiler (moviCompile) v00.95.0 Build 3157 Alpha #1. Restricted distribution.
Loading the image '.\kitten_224.png' ...
Binding...
Running the model...
model run took 562 ticks
tench, Tinca tinca with confidence of 0.738499
barracouta, snoek with confidence of 0.254980
gar, garfish, garpike, billfish, Lepisosteus osseus with confidence of 0.002547
  ```



## License

MIT. See [LICENSE file](https://github.com/Microsoft/Windows-Machine-Learning/blob/master/LICENSE).