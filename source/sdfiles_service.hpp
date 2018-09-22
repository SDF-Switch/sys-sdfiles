#pragma once
#include <switch.h>
#include <stratosphere/iserviceobject.hpp>

class SDFilesService final : public IServiceObject {   
    public:
        Result dispatch(IpcParsedCommand &r, IpcCommand &out_c, u64 cmd_id, u8 *pointer_buffer, size_t pointer_buffer_size) override;
        Result handle_deferred() override {
            /* This service will never defer. */
            return 0;
        }
        
        SDFilesService *clone() override {
            return new SDFilesService();
        }
	private:
		std::tuple<Result, u64> getTest(u64 num);
};
