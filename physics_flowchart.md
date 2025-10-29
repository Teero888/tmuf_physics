* GHIDRA failed to dissamble GmVec3::Zero and RotIndexs

** static member variables:
CPlugSolid::m_MwClassInfo_CPlugSolid
CPlugSolid::m_ParamInfoCount
CPlugSolid::m_ParamInfos
CPlugSolid::s_MwClassInfoStatic
CPlugSolid::s_ParamId_PackBrotherShaders
SMwParamInfos_CPlugSolid::s_Params
CMwTimer::s_CounterSwitchCount

** Missing physics related functions right now but idk, we wont need needed:
- FUN_00939e10 (From CMwTimer::SimulateDeltaTime)
- FUN_00939dd0 (From CMwTimer::InitTimer)
- ReadCurMapLatestEventsFromHarware
- InternalGatherLatestInputs

# missing symbols

CFast.* are template types. i will do them later.
----------------------------------------
- `CFastArray::ArchiveCountAndNods`
- `CFastArray::CFastArray`
- `CFastArray::CopyFromFastArray`
- `CFastArray::Find`
- `CFastArray::ReleaseAll`
- `CFastArray::SetCount`
- `CFastArray::operator`
- `CFastArray::~CFastArray`

- `CFastBuffer::AddNewElem`
- `CFastBuffer::AddRefAll`
- `CFastBuffer::AllocSetCount`
- `CFastBuffer::ArchiveCount`
- `CFastBuffer::ArchiveFastBufferNod`
- `CFastBuffer::CFastBuffer`
- `CFastBuffer::CopyFromFastBuffer`
- `CFastBuffer::DeleteAll`
- `CFastBuffer::FindOrAdd`
- `CFastBuffer::GetCount`
- `CFastBuffer::GetLastElem`
- `CFastBuffer::InitSize`
- `CFastBuffer::Remove`
- `CFastBuffer::ReplaceByLastAt`
- `CFastBuffer::Reset`
- `CFastBuffer::ResetAndFreeMemory`
- `CFastBuffer::SetSizeAtLeast`
- `CFastBuffer::operator`
- `CFastBuffer::~CFastBuffer`

- `CFastBufferCat::GetElemInCat`
- `CFastBufferCat::ReplaceByLastInCatAt`
- `CFastBufferRef::AllocSetCount`
- `CFastBufferWheel::CFastBufferWheel`
- `CFastBufferWheel::ClearWheel`
- `CFastBufferWheel::CopyFromWheel`
- `CFastBufferWheel::Head`
- `CFastBufferWheel::InsertFromStart`
- `CFastBufferWheel::Pull`
- `CFastBufferWheel::Push`
- `CFastBufferWheel::PushNewElem`
- `CFastBufferWheel::Tail`
- `CFastMapTable::Add`
- `CFastMapTable::CFastMapTable`
- `CFastMapTable::Clear`
- `CFastMapTable::GetElem`
- `CFastMapTable::IsPresent`
- `CFastMapTable::operator`
- `CFastRectTable::AddColumn`
- `CFastRectTable::AddLine`
- `CFastRectTable::CFastRectTable`
- `CFastRectTable::Get`
- `CFastRectTable::ReplaceColumnByLastAt`
- `CFastRectTable::ReplaceLineByLastAt`
- `CFastString::Format`
- `CFastString::SetString`
- `CFastString::operator`
- `CFastStringInt::CFastStringInt`
- `CFastStringInt::Concat`
- `CFastStringInt::ConcatFormat`
- `CFastStringInt::SetLength`
- `CFastStringInt::SetString`
- `CFastStringInt::s_Null`
----------------------------------------

Ignore these for now, we will clean up later
----------------------------------------
- `CGameApp::GetBasicDialogs`
- `CGameDialogs::DoMessage`
- `CGameDialogs::HideDialogs`
----------------------------------------

Missing symbols
----------------------------------------
- `CGameControlCardManager::SetGetDataTypeInfosFromNodCallBack`
- `CGameNetwork::SetPlayerInfoType`
- `CGamePlayerCameraSet::PlayerGameMobilIdSet`
- `CGamePlayerInfo::CGamePlayerInfo`
- `CGamePlayerInfo::~CGamePlayerInfo`
- `CGamePlayground::UpdateFromSettings`
- `CGameRace::SetStatus`
- `CHmsCamera::s_AsyncPrevDeltaT`
- `CHmsItem::SetIsForcePointDynamicCollisionResponse`
- `CHmsItem::s_CollisionGroupPairs`
- `CHmsShadowGroup::CHmsShadowGroup`
- `CHmsStateDyna::OldRestoreState`
- `CHmsStateDyna::Reset`
- `CHmsStateDyna::RestoreState`
- `CHmsZoneDynamic::s_IsTweakedSpeeds`
- `CHmsZoneElem::CHmsZoneElem`
- `CMwClassInfo::IsMwParamIdEqualName`
- `CMwClassInfo::MwGetNearestFather`
- `CMwCmdBufferCore::TheCoreCmdBuffer`
- `CMwEngineMain::TheMainEngine`
- `CMwId::Archive`
- `CMwId::CMwId`
- `CMwId::CreateFromLocalIndex`
- `CMwId::GetName`
- `CMwId::SetLocalName`
- `CMwNodRef::MwSetNod`
- `CMwParamClass::SetValue`
- `CMwParamFastBuffer::GetValue`
- `CMwParamFastBuffer::SetValue`
- `CMwParamFastBuffer::SubValue`
- `CMwParamVec3::GetValue`
- `CMwParamVec3::SetValue`
- `CMwProfiler::GetCPUFrequency`
- `CPlug::CPlug`
- `CPlug::~CPlug`
- `CPlugBitmap::CPlugBitmap`
- `CPlugBitmap::SetDefaultTexAddress`
- `CPlugBitmap::SetImage`
- `CPlugFileGen::CPlugFileGen`
- `CPlugFileGen::GenChecker`
- `CPlugMaterial::DoesContainShader`
- `CPlugMaterial::GetSupportedShader`
- `CPlugPhysicalObject::SetComPosAndInertiaMatrixFromTreeBoundingBox`
- `CScanner::CScanner`
- `CScene2d::OnNodLoaded`
- `CSystemArchiveNod::Compare`
- `CSystemArchiveNod::Duplicate`
- `CSystemArchiveNod::LoadFromFid`
- `CSystemArchiveNod::LoadResource`
- `CSystemConfig::s_SystemConfig`
- `CSystemEngine::UnbindFid`
- `CSystemFid::ParametrizedGetAnyLoadedNodLooselyFittingTheParams`
- `CSystemFidFile::GetFullName`
- `CSystemFidParameters::AddParam`
- `CSystemFidParameters::CSystemFidParameters`
- `CSystemFidParameters::Empty`
- `CSystemFidParameters::GetCurrentParameters`
- `CSystemFidParameters::GetParamValue`
- `CSystemFidParameters::~CSystemFidParameters`
- `CTrackManiaNetwork::Hack_ResetAfterValidation`
- `CTrackManiaRace::ActionFakeFinishLine`
- `CTrackManiaRace::ActionFakeIsRaceRunning`
- `CTrackManiaRace::ActionRespawn_1`
- `CTrackManiaRace::ActionVehicleAccelerate_1`
- `CTrackManiaRace::ActionVehicleBrake_1`
- `CTrackManiaRace::ActionVehicleGas_1`
- `CTrackManiaRace::ActionVehicleHorn_1`
- `CTrackManiaRace::ActionVehicleSteerLeft_1`
- `CTrackManiaRace::ActionVehicleSteerRight_1`
- `CTrackManiaRace::ActionVehicleSteer_1`
- `CVisionViewportNull::SetFullScreenGammaRamp`
- `GmArchive::ReadQuat_6`
- `GmArchive::ReadVec3Pos_12`
- `GmArchive::ReadVec3Pos_9`
- `GmArchive::ReadVec3_4`
- `GmArchive::WriteQuat_6`
- `GmArchive::WriteVec3Pos_12`
- `GmArchive::WriteVec3Pos_9`
- `GmArchive::WriteVec3_4`
- `GmFrustum::GetVertices4AtZ`
- `GmMap2::GmMap2`
- `GmVec2::operator`
- `GxTexCoordSet::Alloc`
- `GxTexCoordSet::s_ByteSizeByKinds`
- `GxTexCoordSet::s_DefaultZW_11`
- `SHmsSphereBufferContact::MergeAndAddToCollisions`
- `SHmsSphereBufferContact::s_SphereContactMergeThreshold`
- `SPlugGpuLoadFx::~SPlugGpuLoadFx`
- `SRpcPlayerQuickInfo::Reset`
- `SRpcPlayerQuickInfo::~SRpcPlayerQuickInfo`
- `STmValidateParam::operator`
- `VertexCache::~VertexCache`
-------------------------------


Missing structs/classes:
-------------------------------
- all
-------------------------------------
