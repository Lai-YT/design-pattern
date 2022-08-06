package facade;

import java.io.File;

import some_complex_media_library.AudioMixer;
import some_complex_media_library.BitrateReader;
import some_complex_media_library.Codec;
import some_complex_media_library.CodecFactory;
import some_complex_media_library.Mpeg4CompressionCodec;
import some_complex_media_library.OggCompressionCodec;
import some_complex_media_library.VideoFile;

/// Facade provides simple interface of video conversion.
public class VideoConversionFacade {
    public File convertVideo(final String fileName, final String format) {
        System.out.println("VideoConversionFacade: conversion started.");

        final VideoFile file = new VideoFile(fileName);
        final Codec sourceCodec = CodecFactory.extract(file);
        Codec destinationCodec = null;
        if (format.equals("mp4")) {
            destinationCodec = new Mpeg4CompressionCodec();
        } else {
            destinationCodec = new OggCompressionCodec();
        }
        VideoFile buffer = BitrateReader.read(file, sourceCodec);
        VideoFile intermediateResult = BitrateReader.convert(buffer, destinationCodec);
        File result = (new AudioMixer()).fix(intermediateResult);

        System.out.println("VideoConversionFacade: conversion completed.");
        return result;
    }
}
