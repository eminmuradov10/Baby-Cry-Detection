# Embedded AI Research: Baby Cry Detection

## Overview

This project aims to develop a baby cry detection model and deploy it to the NXP MIMTRX1064 Microcontroller using MCUXpresso IDE. The model distinguishes among 3 categories: baby laugh, baby cry, and silence.

## Dataset

The dataset consists of 432 audio recordings, with 108 recordings for each category. Each recording is 5 seconds long. The dataset was obtained from [this GitHub repository](https://github.com/giulbia/baby_cry_detection/tree/master/data).

## Model Development

### Data Preparation

To prepare the data for training, the audio recordings were converted to the pcm_s16le format using the [ffmpeg](https://www.gyan.dev/ffmpeg/builds/) tool. This format is commonly used for converting the audio files to feasible format. A sample code for conversion has been provided below:

```
import os

input_folder = 'Baby_Cry'
output_folder = 'Baby_Cry_pcm_s16le_format'

if not os.path.exists(output_folder):
    os.makedirs(output_folder)

for filename in os.listdir(input_folder):
    if filename.endswith(".wav") or filename.endswith(".ogg"):
        input_file = os.path.join(input_folder, filename)
        output_file = os.path.join(output_folder, os.path.splitext(filename)[0] + ".wav")
        os.system(f"ffmpeg -y -i {input_file} -acodec pcm_s16le -ac 1 {output_file}")
```

### Training

The model was trained using [Edge Impulse](https://edgeimpulse.com/), which provides a user-friendly interface for developing ML models. The training process involved uploading the dataset, configuring the model, and validating the model's performance.

### Model Conversion

After training and testing the model in the Edge Impulse portal, the Classifier model (TensorFlow Lite float32) was downloaded. This model file was converted to a binary file using the following command:

```bash
xxd -i ./ds_cnn.tflite > ./ds_cnn.h
```

### Deployment

The model was deployed to the NXP MIMTRX1064 Microcontroller using the MCUXpresso IDE. The [tutorial](https://www.nxp.com/docs/en/application-note/AN13065_Rev0.pdf) provided detailed instructions for deploying the model to the microcontroller.

## Important Files

- `commands.h`: Contains sample test sounds to test the model on the MIMTRX1064 Microcontroller. These sounds can be converted to array format using a sample Python script below:
```
from scipy.io import wavfile
import os
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('--wave', type=str, default=\
                    "baby_laugh1.wav",
                    help='Get audio wave file')
cmd_args, _ = parser.parse_known_args()
audioFile = cmd_args.wave

# Path to saved model directory

rate, data = wavfile.read(audioFile)
with open('commands.h', 'w') as fout:
  print('const int16_t WAVE_DATA[]= {', file=fout)
  data.tofile(fout, ',', '%d')
  print('};\n', file=fout)
print('file commands.h generated..')
```
- `kws_mfcc.h`: Contains the necessary settings for feature extraction from the test sounds in `commands.h` .

## Conclusion

This project demonstrates the feasibility of deploying ML models to resource-limited devices like microcontrollers. By using Edge Impulse and NXP's tools, a custom ML model can be trained and deployed to embedded systems for various applications, such as sound detection, image classification and etc.

## Tutorial Reference

This project was developed following a similar project outlined in the technical tutorial [AN13065](https://www.nxp.com/docs/en/application-note/AN13065_Rev0.pdf) by NXP. The tutorial provided valuable insights and guidance from setup to deployment, which were instrumental in the development of this project.

