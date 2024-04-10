#include "ZHMPrimitives.h"
#include "ZHMTypeInfo.h"

#include <External/simdjson_helpers.h>

void IZHMTypeInfo::RegisterPrimitiveTypes()
{
	new ZHMTypeInfo("int8", sizeof(int8), alignof(int8),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(static_cast<int>(*static_cast<int8_t*>(p_Data)));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<int8_t*>(p_Target) = simdjson::from_json_int8(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<int8_t*>(p_Left) == *reinterpret_cast<int8_t*>(p_Right);
		});

	new ZHMTypeInfo("uint8", sizeof(uint8), alignof(uint8),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(static_cast<int>(*static_cast<uint8_t*>(p_Data)));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<uint8*>(p_Target) = simdjson::from_json_uint8(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<uint8_t*>(p_Left) == *reinterpret_cast<uint8_t*>(p_Right);
		});

	new ZHMTypeInfo("int16", sizeof(int16), alignof(int16),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<int16_t*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<int16*>(p_Target) = simdjson::from_json_int16(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<int16_t*>(p_Left) == *reinterpret_cast<int16_t*>(p_Right);
		});

	new ZHMTypeInfo("uint16", sizeof(uint16), alignof(uint16),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<uint16_t*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<uint16*>(p_Target) = simdjson::from_json_uint16(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<uint16_t*>(p_Left) == *reinterpret_cast<uint16_t*>(p_Right);
		});

	new ZHMTypeInfo("int32", sizeof(int32), alignof(int32),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<int32_t*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<int32*>(p_Target) = simdjson::from_json_int32(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<int32_t*>(p_Left) == *reinterpret_cast<int32_t*>(p_Right);
		});

	new ZHMTypeInfo("uint32", sizeof(uint32), alignof(uint32),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<uint32_t*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<uint32_t*>(p_Target) = simdjson::from_json_uint32(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<uint32_t*>(p_Left) == *reinterpret_cast<uint32_t*>(p_Right);
		});

	new ZHMTypeInfo("int64", sizeof(int64), alignof(int64),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<int64_t*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<int64*>(p_Target) = simdjson::from_json_int64(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<int64_t*>(p_Left) == *reinterpret_cast<int64_t*>(p_Right);
		});

	new ZHMTypeInfo("uint64", sizeof(uint64), alignof(uint64),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<uint64_t*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<uint64*>(p_Target) = simdjson::from_json_uint64(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<uint64_t*>(p_Left) == *reinterpret_cast<uint64_t*>(p_Right);
		});

	new ZHMTypeInfo("float32", sizeof(float32), alignof(float32),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<float*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<float32*>(p_Target) = simdjson::from_json_float32(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<float32*>(p_Left) == *reinterpret_cast<float32*>(p_Right);
		});

	new ZHMTypeInfo("float64", sizeof(float64), alignof(float64),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<double*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<float64*>(p_Target) = simdjson::from_json_float64(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<float64*>(p_Left) == *reinterpret_cast<float64*>(p_Right);
		});

	new ZHMTypeInfo("bool", sizeof(bool), alignof(bool),
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << simdjson::as_json_string(*static_cast<bool*>(p_Data));
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
			*reinterpret_cast<bool*>(p_Target) = simdjson::from_json_bool(p_Document);
		}, [](void*, ZHMSerializer&, zhmptr_t) {},
		[](void* p_Left, void* p_Right)
		{
			return *reinterpret_cast<bool*>(p_Left) == *reinterpret_cast<bool*>(p_Right);
		});

	new ZHMTypeInfo("ZString", sizeof(ZString), alignof(ZString), ZString::WriteSimpleJson, ZString::FromSimpleJson, ZString::Serialize, ZString::Equals, ZString::Destroy);
	
	new ZHMTypeInfo("ZRepositoryID", sizeof(ZRepositoryID), alignof(ZRepositoryID),ZRepositoryID::WriteSimpleJson, ZRepositoryID::FromSimpleJson, ZRepositoryID::Serialize, ZRepositoryID::Equals);
	
	new ZHMTypeInfo("ZVariant", sizeof(ZVariant), alignof(ZVariant), ZVariant::WriteSimpleJson, ZVariant::FromSimpleJson, ZVariant::Serialize, ZVariant::Equals, ZVariant::Destroy);

	new ZHMTypeInfo("void", 0, 0,
		[](void* p_Data, std::ostream& p_Stream)
		{
			p_Stream << "null";
		},
		[](simdjson::ondemand::value p_Document, void* p_Target)
		{
		}, [](void*, ZHMSerializer&, zhmptr_t) {});
}
