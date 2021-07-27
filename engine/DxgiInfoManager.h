#pragma once
#include "ConfigureWindows.h"
#include <wrl.h>
#include <dxgidebug.h>
#include <vector>
#include <string>

class DxgiInfoManager
{
public:
	DxgiInfoManager();
	~DxgiInfoManager() = default ;
	DxgiInfoManager(const DxgiInfoManager&) = delete;
	DxgiInfoManager& operator=(const DxgiInfoManager&) = delete;
	void Set() noexcept;
	std::vector<std::string> GetMessages() const;
private:
	unsigned long long next = 0u;
	Microsoft::WRL::ComPtr<IDXGIInfoQueue> pDxgiInfoQueue = nullptr;
};

