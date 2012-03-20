//
//  UIScriptASTWith.h
//  Created by Karl Krukow on 12/08/11.
//  Copyright 2011 LessPainful. All rights reserved.
//

#import "UIScriptAST.h"
typedef enum {
    UIScriptLiteralTypeUnknown,
    UIScriptLiteralTypeString,
    UIScriptLiteralTypeInteger,
    UIScriptLiteralTypeBool
} UIScriptLiteralType;

static NSString *LP_QUERY_JS = @"(function(){function isHostMethod(object,property){var t=typeof object[property];return t==='function'||(!!(t==='object'&&object[property]))||t==='unknown';}var NODE_TYPES={1:'ELEMENT_NODE',2:'ATTRIBUTE_NODE',3:'TEXT_NODE',9:'DOCUMENT_NODE'};function toJSON(object){var res,i,N;if(typeof object==='undefined'){throw {message:'Calling toJSON with undefined'};}else{if(object instanceof Node){res={};if(isHostMethod(object,'getBoundingClientRect')){res['rect']=object.getBoundingClientRect();}res.nodeType=NODE_TYPES[object.nodeType]||res.nodeType+' (Unexpected)';res.nodeName=object.nodeName;res.id=object.id||'';res['class']=object.className||'';res.html=object.outerHTML||'';res.textContent=object.textContent;}else{if(object instanceof NodeList||(typeof object=='object'&&object&&typeof object.length==='number'&&object.length>0&&typeof object[0]!=='undefined')){res=[];for(i=0,N=object.length;i<N;i++){res[i]=toJSON(object[i]);}}else{res=object;}}}return res;}var exp='%@',queryType='%@',nodes=null,res=[],i,N;try{if(queryType==='xpath'){nodes=document.evaluate(exp,document,null,XPathResult.ORDERED_NODE_SNAPSHOT_TYPE,null);for(i=0,N=nodes.snapshotLength;i<N;i++){res[i]=nodes.snapshotItem(i);}}else{res=document.querySelectorAll(exp);}}catch(e){return JSON.stringify({error:'Exception while running query: '+exp,details:e.toString()});}return JSON.stringify(toJSON(res));})();";

@interface UIScriptASTWith : UIScriptAST {
    NSString *_selectorName;
    SEL _selector;
    NSObject* _objectValue;
    BOOL _boolValue;
    NSInteger _integerValue;
    
    UIScriptLiteralType _valueType;
    
}
@property (nonatomic, assign) NSString *selectorName;
@property (nonatomic,assign) SEL selector;
@property (nonatomic, assign) NSInteger timeout;
@property (nonatomic,retain) NSObject *objectValue;
@property (nonatomic,assign) BOOL boolValue;
@property (nonatomic,assign) NSInteger integerValue;
@property (nonatomic,assign) UIScriptLiteralType valueType;
 

- (id)initWithSelectorName:(NSString *)selectorName;
@end
