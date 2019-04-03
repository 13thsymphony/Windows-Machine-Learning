#pragma once

#include "DXCoreHelper.g.h"

namespace winrt::DXCore_WinRTComponent::implementation
{
    struct DXCoreHelper : DXCoreHelperT<DXCoreHelper>
    {
        DXCoreHelper();

        winrt::Windows::AI::MachineLearning::LearningModelDevice GetDeviceFromVpuAdapter();
        winrt::Windows::AI::MachineLearning::LearningModelDevice GetDeviceFromComputeOnlyAdapter();
        winrt::Windows::AI::MachineLearning::LearningModelDevice GetDeviceFromGraphicsAdapter();

    private:
        winrt::Windows::AI::MachineLearning::LearningModelDevice GetLearningModelDeviceFromAdapter(IDXCoreAdapter* adapter);

        winrt::com_ptr<IDXCoreAdapterFactory> _factory;
    };
}

namespace winrt::DXCore_WinRTComponent::factory_implementation
{
    struct DXCoreHelper : DXCoreHelperT<DXCoreHelper, implementation::DXCoreHelper>
    {
    };
}
