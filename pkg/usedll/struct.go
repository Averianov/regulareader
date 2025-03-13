package usedll

import (
	"unsafe"
)

type TResultContainer struct {
	result_type uint32 // eRPRM_ResultType
	light       uint32 // eRPRM_Lights
	buf_length  uint32
	buffer      unsafe.Pointer
	XML_length  uint32
	XML_buffer  unsafe.Pointer
	list_idx    uint32
	page_idx    uint32
}
