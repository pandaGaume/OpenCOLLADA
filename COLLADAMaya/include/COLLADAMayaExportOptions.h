/*
    Copyright (c) 2008 Intel Corporation
    Copyright (c) 2005-2008 Sony Computer Entertainment America
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADAMaya.

    COLLADAMaya is free software; you can redistribute it and/or modify
    it under the terms of the MIT License as published by the
    Massachusetts Institute of Technology.

    COLLADAMaya is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    MIT License for more details.

    You should have received a copy of the MIT License along with
    COLLADAMaya; see the file COPYING. If not have a look here:
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADA_MAYA_EXPORT_OPTIONS_H__
#define __COLLADA_MAYA_EXPORT_OPTIONS_H__

#include <maya/MPxFileTranslator.h>

namespace COLLADAMaya
{
    /**
     * COLLADA Export options
     * Class which manages the export options.
     * All options are stored statically to allow easy retrieval
     * from any class. At some point we may want to
     * modify this class to use a singleton pattern...
     */

    class ExportOptions
    {

    private:
        static bool mBakeTransforms;
        static bool mBakeLighting;
        static bool mRelativePaths;
        static bool mExportPolygonMeshes;
        static bool mExportLights;
        static bool mExportCameras;
        static bool mExportJointsAndSkin;
        static bool mExportAnimations;
        static bool mExportCameraAsLookat;
        static bool mExportTriangles;
        static bool mExportInvisibleNodes;
        static bool mExportDefaultCameras;
        static bool mExportNormals;
        static bool mExportTexCoords;
        static bool mExportVertexColors;
        static bool mExportVertexColorAnimations;
        static bool mExportTangents;
        static bool mExportTexTangents;
        static bool mExportMaterialsOnly;
        static bool mExportConstraints;
        static bool mRemoveStaticCurves;
        static bool mExportPhysics;
        static bool mExportXRefs;
        static bool mDereferenceXRefs;
        static bool mCameraXFov;
        static bool mCameraYFov;

        static int mExclusionSetMode;
        static MStringArray mExclusionSets;

        static bool mIsSampling;
        static bool mCurveConstrainSampling;
        static MFloatArray mSamplingFunction;

    public:
        // Reset all options to their default values.
        static void set ( const MString &optionsString );

        // Should the transforms be baked into a single matrix,
        // as opposed to decomposed into primitive collada
        // transforms (e.g. translate, rotate, scale)?
        // Default: FALSE
        static bool bakeTransforms()
        {
            return mBakeTransforms;
        }

        static bool exportPolygonMeshes()
        {
            return mExportPolygonMeshes;
        }

        static bool bakeLighting()
        {
            return mBakeLighting;
        }

        static bool isSampling()
        {
            return mIsSampling;
        }

        static bool curveConstrainSampling()
        {
            return mCurveConstrainSampling;
        }

        static bool removeStaticCurves()
        {
            return mRemoveStaticCurves;
        }

        static bool exportCameraAsLookat()
        {
            return mExportCameraAsLookat;
        }

        static bool relativePaths()
        {
            return mRelativePaths;
        }

        // Export filters
        static bool exportLights()
        {
            return mExportLights;
        }

        static bool exportCameras()
        {
            return mExportCameras;
        }

        static bool exportJointsAndSkin()
        {
            return mExportJointsAndSkin;
        }

        static bool exportAnimations()
        {
            return mExportAnimations;
        }

        static bool exportTriangles()
        {
            return mExportTriangles;
        }

        static bool exportInvisibleNodes()
        {
            return mExportInvisibleNodes;
        }

        static bool exportDefaultCameras()
        {
            return mExportDefaultCameras;
        }

        static bool exportNormals()
        {
            return mExportNormals;
        }

        static bool exportTexCoords()
        {
            return mExportTexCoords;
        }

        static bool exportVertexColors()
        {
            return mExportVertexColors;
        }

        static bool exportVertexColorAnimations()
        {
            return mExportVertexColorAnimations;
        }

        static bool exportTangents()
        {
            return mExportTangents;
        }

        static bool exportTexTangents()
        {
            return mExportTexTangents;
        }

        // DF Export Filters
        static bool ExportConstraints()
        {
            return mExportConstraints;
        }

        static bool ExportPhysics()
        {
            return mExportPhysics;
        }

        static MStringArray GetExclusionSets()
        {
            return mExclusionSets;
        }

        // XRef options
        static bool exportXRefs()
        {
            return mExportXRefs;
        }

        static bool dereferenceXRefs()
        {
            return mDereferenceXRefs;
        }

        // Camera options
        static bool cameraXFov()
        {
            return mCameraXFov;
        }

        static bool cameraYFov()
        {
            return mCameraYFov;
        }

    };

    /**
     * Class which manages the import options.
     */

    class CImportOptions
    {

    private:
        static bool mIsOpenCall;
        static bool mIsReferenceCall;
        static bool mFileLoadDeferRefOptionVar;
        static bool mHasError;

        static bool mImportUpAxis;
        static bool mImportUnits;
        static bool mImportNormals;

    public:
        static void set ( const MString &optionsString, MPxFileTranslator::FileAccessMode mode );

        static bool isOpenMode()
        {
            return mIsOpenCall;
        }

        static bool isReferenceMode()
        {
            return mIsReferenceCall;
        }

        static bool fileLoadDeferReferencesOption()
        {
            return mFileLoadDeferRefOptionVar;
        }

        static bool hasError()
        {
            return mHasError;
        }

        static bool importUpAxis()
        {
            return mImportUpAxis;
        }

        static bool importUnits()
        {
            return mImportUnits;
        }

        static bool importNormals()
        {
            return mImportNormals;
        }

        static void setErrorFlag()
        {
            mHasError = true;
        }

    };
}

#endif // __COLLADA_MAYA_EXPORT_OPTIONS_H__