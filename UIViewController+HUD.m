//
//  UIViewController+HUD.m
//
//  Created by Gabi Martelo on 09/11/14.
//  Copyright (c) 2014 Startcapps. All rights reserved.
//
/*
 The MIT License (MIT)
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#import "UIViewController+HUD.h"
#import <objc/runtime.h>
#import "STSpinnerView.h"

@implementation UIViewController (HUD)
@dynamic spinnerView;

- (void)setSpinnerView:(STSpinnerView *)spinnerView {
    objc_setAssociatedObject(self, @selector(spinnerView), spinnerView, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (STSpinnerView *)spinnerView {
    return objc_getAssociatedObject(self, @selector(spinnerView));
}

- (void)showHud {
    return [self showHudWithMessage:nil];
}

- (void)showHudWithMessage:(NSString *)aMessage {
    return[self showHudWithMessage:aMessage allowUserInteraction:YES];
}

- (void)showHudWithMessage:(NSString *)aMessage allowUserInteraction:(BOOL)allowUserInteraction {
    if (!self.spinnerView) {
        self.spinnerView = [STSpinnerView spinnerCenteredInView:self.view];
        [self.view addSubview:self.spinnerView];
    }
    [self.spinnerView startAnimatingWithMessage:aMessage allowUserInteraction:allowUserInteraction];
}

- (void)hideHud {
    if (self.spinnerView) {
        [self.spinnerView stopAnimating];
    }
}
@end
