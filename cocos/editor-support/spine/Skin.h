/******************************************************************************
 * Spine Runtime Software License - Version 1.1
 * 
 * Copyright (c) 2013, Esoteric Software
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms in whole or in part, with
 * or without modification, are permitted provided that the following conditions
 * are met:
 * 
 * 1. A Spine Essential, Professional, Enterprise, or Education License must
 *    be purchased from Esoteric Software and the license must remain valid:
 *    http://esotericsoftware.com/
 * 2. Redistributions of source code must retain this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer.
 * 3. Redistributions in binary form must reproduce this license, which is the
 *    above copyright notice, this declaration of conditions and the following
 *    disclaimer, in the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef SPINE_SKIN_H_
#define SPINE_SKIN_H_

#include <spine/Attachment.h>

#ifdef __cplusplus
extern "C" {
#endif

struct spSkeleton;

typedef struct {
	const char* const name;
} spSkin;

spSkin* spSkin_create (const char* name);
void spSkin_dispose (spSkin* self);

/* 向皮肤中添加附件The Skin owns the attachment. */
void spSkin_addAttachment (spSkin* self, int slotIndex, const char* name, spAttachment* attachment);
/* 查找指定附件，如果未找到返回0. */
spAttachment* spSkin_getAttachment (const spSkin* self, int slotIndex, const char* name);

/* 查找指定附件，如果未找到槽（slot）或附件（attachment）返回0. */
const char* spSkin_getAttachmentName (const spSkin* self, int slotIndex, int attachmentIndex);

/** 如果之前的皮肤加载了附件在将他添加到新的皮肤中来. */
void spSkin_attachAll (const spSkin* self, struct spSkeleton* skeleton, const spSkin* oldspSkin);

#ifdef SPINE_SHORT_NAMES
typedef spSkin Skin;
#define Skin_create(...) spSkin_create(__VA_ARGS__)
#define Skin_dispose(...) spSkin_dispose(__VA_ARGS__)
#define Skin_addAttachment(...) spSkin_addAttachment(__VA_ARGS__)
#define Skin_getAttachment(...) spSkin_getAttachment(__VA_ARGS__)
#define Skin_getAttachmentName(...) spSkin_getAttachmentName(__VA_ARGS__)
#define Skin_attachAll(...) spSkin_attachAll(__VA_ARGS__)
#endif

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SKIN_H_ */
