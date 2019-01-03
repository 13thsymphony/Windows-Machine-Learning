using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Windows.Media;
using Windows.Storage;
using Windows.Storage.Streams;
using Windows.AI.MachineLearning;
namespace SnapCandy
{
    
    public sealed class Input
    {
        public ImageFeatureValue inputImage; // BitmapPixelFormat: Bgra8, BitmapAlphaMode: Premultiplied, width: 720, height: 720
    }
    
    public sealed class Output
    {
        public ImageFeatureValue outputImage; // BitmapPixelFormat: Bgra8, BitmapAlphaMode: Premultiplied, width: 720, height: 720
    }
    
    public sealed class Model
    {
        private LearningModel model;
        private LearningModelSession session;
        private LearningModelBinding binding;
        public static async Task<Model> CreateFromStreamAsync(IRandomAccessStreamReference stream)
        {
            Model learningModel = new Model();
            learningModel.model = await LearningModel.LoadFromStreamAsync(stream);
            learningModel.session = new LearningModelSession(learningModel.model);
            learningModel.binding = new LearningModelBinding(learningModel.session);
            return learningModel;
        }
        public async Task<Output> EvaluateAsync(Input input)
        {
            binding.Bind("inputImage", input.inputImage);
            var result = await session.EvaluateAsync(binding, "0");
            var output = new Output();
            output.outputImage = result.Outputs["outputImage"] as ImageFeatureValue;
            return output;
        }
    }
}
