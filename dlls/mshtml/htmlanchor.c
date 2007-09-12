/*
 * Copyright 2007 Jacek Caban for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <stdarg.h>
#include <stdio.h>

#define COBJMACROS

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "winnls.h"
#include "ole2.h"

#include "wine/debug.h"

#include "mshtml_private.h"

WINE_DEFAULT_DEBUG_CHANNEL(mshtml);

typedef struct {
    const IHTMLAnchorElementVtbl *lpHTMLAnchorElementVtbl;

    HTMLElement *element;
} HTMLAnchorElement;

#define HTMLANCHOR(x)  ((IHTMLAnchorElement*)  &(x)->lpHTMLAnchorElementVtbl)

#define HTMLANCHOR_THIS(iface) DEFINE_THIS(HTMLAnchorElement, HTMLAnchorElement, iface)

static HRESULT WINAPI HTMLAnchorElement_QueryInterface(IHTMLAnchorElement *iface,
        REFIID riid, void **ppv)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    HRESULT hres;

    *ppv = NULL;

    if(IsEqualGUID(&IID_IUnknown, riid)) {
        TRACE("(%p)->(IID_IUnknown %p)\n", This, ppv);
        *ppv = HTMLANCHOR(This);
    }else if(IsEqualGUID(&IID_IDispatch, riid)) {
        TRACE("(%p)->(IID_IDispatch %p)\n", This, ppv);
        *ppv = HTMLANCHOR(This);
    }else if(IsEqualGUID(&IID_IHTMLAnchorElement, riid)) {
        TRACE("(%p)->(IID_IHTMLAnchorElement %p)\n", This, ppv);
        *ppv = HTMLANCHOR(This);
    }

    if(*ppv) {
        IUnknown_AddRef((IUnknown*)*ppv);
        return S_OK;
    }

    hres = HTMLElement_QI(This->element, riid, ppv);
    if(FAILED(hres))
        WARN("(%p)->(%s %p)\n", This, debugstr_guid(riid), ppv);

    return hres;
}

static ULONG WINAPI HTMLAnchorElement_AddRef(IHTMLAnchorElement *iface)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);

    TRACE("(%p)\n", This);

    return IHTMLDocument2_AddRef(HTMLDOC(This->element->node->doc));
}

static ULONG WINAPI HTMLAnchorElement_Release(IHTMLAnchorElement *iface)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);

    TRACE("(%p)\n", This);

    return IHTMLDocument2_Release(HTMLDOC(This->element->node->doc));
}

static HRESULT WINAPI HTMLAnchorElement_GetTypeInfoCount(IHTMLAnchorElement *iface, UINT *pctinfo)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, pctinfo);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_GetTypeInfo(IHTMLAnchorElement *iface, UINT iTInfo,
                                              LCID lcid, ITypeInfo **ppTInfo)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%u %u %p)\n", This, iTInfo, lcid, ppTInfo);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_GetIDsOfNames(IHTMLAnchorElement *iface, REFIID riid,
                                                LPOLESTR *rgszNames, UINT cNames,
                                                LCID lcid, DISPID *rgDispId)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s %p %u %u %p)\n", This, debugstr_guid(riid), rgszNames, cNames,
                                        lcid, rgDispId);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_Invoke(IHTMLAnchorElement *iface, DISPID dispIdMember,
                            REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDispParams,
                            VARIANT *pVarResult, EXCEPINFO *pExcepInfo, UINT *puArgErr)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%d %s %d %d %p %p %p %p)\n", This, dispIdMember, debugstr_guid(riid),
            lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_href(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_href(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_target(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_target(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_rel(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_rel(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_rev(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_rev(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_urn(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_urn(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_Methods(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_Methods(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_name(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_name(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_host(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_host(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_hostname(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_hostname(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_pathname(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_pathname(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_port(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_port(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_protocol(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_protocol(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_search(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_search(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_hash(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_hash(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_onblur(IHTMLAnchorElement *iface, VARIANT v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->()\n", This);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_onblur(IHTMLAnchorElement *iface, VARIANT *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_onfocus(IHTMLAnchorElement *iface, VARIANT v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->()\n", This);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_onfocus(IHTMLAnchorElement *iface, VARIANT *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_accessKey(IHTMLAnchorElement *iface, BSTR v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%s)\n", This, debugstr_w(v));
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_accessKey(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_protocolLong(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_mimeType(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_nameProp(IHTMLAnchorElement *iface, BSTR *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_put_tabIndex(IHTMLAnchorElement *iface, short v)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->()\n", This);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_get_tabIndex(IHTMLAnchorElement *iface, short *p)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)->(%p)\n", This, p);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_focus(IHTMLAnchorElement *iface)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)\n", This);
    return E_NOTIMPL;
}

static HRESULT WINAPI HTMLAnchorElement_blur(IHTMLAnchorElement *iface)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    FIXME("(%p)\n", This);
    return E_NOTIMPL;
}

static void HTMLAnchorElement_destructor(IUnknown *iface)
{
    HTMLAnchorElement *This = HTMLANCHOR_THIS(iface);
    mshtml_free(This);
}

static const IHTMLAnchorElementVtbl HTMLAnchorElementVtbl = {
    HTMLAnchorElement_QueryInterface,
    HTMLAnchorElement_AddRef,
    HTMLAnchorElement_Release,
    HTMLAnchorElement_GetTypeInfoCount,
    HTMLAnchorElement_GetTypeInfo,
    HTMLAnchorElement_GetIDsOfNames,
    HTMLAnchorElement_Invoke,
    HTMLAnchorElement_put_href,
    HTMLAnchorElement_get_href,
    HTMLAnchorElement_put_target,
    HTMLAnchorElement_get_target,
    HTMLAnchorElement_put_rel,
    HTMLAnchorElement_get_rel,
    HTMLAnchorElement_put_rev,
    HTMLAnchorElement_get_rev,
    HTMLAnchorElement_put_urn,
    HTMLAnchorElement_get_urn,
    HTMLAnchorElement_put_Methods,
    HTMLAnchorElement_get_Methods,
    HTMLAnchorElement_put_name,
    HTMLAnchorElement_get_name,
    HTMLAnchorElement_put_host,
    HTMLAnchorElement_get_host,
    HTMLAnchorElement_put_hostname,
    HTMLAnchorElement_get_hostname,
    HTMLAnchorElement_put_pathname,
    HTMLAnchorElement_get_pathname,
    HTMLAnchorElement_put_port,
    HTMLAnchorElement_get_port,
    HTMLAnchorElement_put_protocol,
    HTMLAnchorElement_get_protocol,
    HTMLAnchorElement_put_search,
    HTMLAnchorElement_get_search,
    HTMLAnchorElement_put_hash,
    HTMLAnchorElement_get_hash,
    HTMLAnchorElement_put_onblur,
    HTMLAnchorElement_get_onblur,
    HTMLAnchorElement_put_onfocus,
    HTMLAnchorElement_get_onfocus,
    HTMLAnchorElement_put_accessKey,
    HTMLAnchorElement_get_accessKey,
    HTMLAnchorElement_get_protocolLong,
    HTMLAnchorElement_get_mimeType,
    HTMLAnchorElement_get_nameProp,
    HTMLAnchorElement_put_tabIndex,
    HTMLAnchorElement_get_tabIndex,
    HTMLAnchorElement_focus,
    HTMLAnchorElement_blur
};

void HTMLAnchorElement_Create(HTMLElement *element)
{
    HTMLAnchorElement *ret = mshtml_alloc(sizeof(HTMLAnchorElement));

    ret->lpHTMLAnchorElementVtbl = &HTMLAnchorElementVtbl;
    ret->element = element;

    element->impl = (IUnknown*)HTMLANCHOR(ret);
    element->destructor = HTMLAnchorElement_destructor;
}
