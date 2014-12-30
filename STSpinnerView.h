//
//  STSpinnerView.h
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

#import <UIKit/UIKit.h>

@interface STSpinnerView : UIView
/*!
 * The view background color that will be shown if there is a message
 */
@property (strong, nonatomic) UIColor *bgColor;

/*!
 * The text color for the optional message
 */
@property (strong, nonatomic) UIColor *textColor;

/*!
 * The text font for the optional message
 */
@property (strong, nonatomic) UIFont *textFont;

/*!
 * The optional message shown below the spinner image
 */
@property (copy, nonatomic) NSString *message;

/**
 * Create a spinnerView which frame is centered to the given view
 *
 * @param aView A view that will contain the spinner
 * @return An instance of the SpinnerView
 */
+ (instancetype)spinnerCenteredInView:(UIView *)aView;

/**
 * Create a spinnerView
 *
 * @param
 * @return An instance of the SpinnerView
 */
+ (instancetype)spinnerView;

/**
 * Show the spinner with an optional message
 *
 * @param aMessage An optional message to show to the user
 * @param allowUserInteraction YES if the screen interactions should be disabled while the spinner is animating
 * @return
 */
- (void)startAnimatingWithMessage:(NSString *)aMessage allowUserInteraction:(BOOL)allowUserInteraction;

/**
 * Show the spinner with an optional message
 *
 * @param aMessage An optional message to show to the user
 * @return
 */
- (void)startAnimatingWithMessage:(NSString *)aMessage;

/**
 * Show the spinner
 *
 * @param
 * @return
 */
- (void)startAnimating;

/**
 * Stop the spinner
 *
 * @discussion This method enables screen user interaction if it was disabled previosly
 * @param
 * @return
 */
- (void)stopAnimating;

/**
 * Check if the spinner is animating
 *
 * @param
 * @return YES if the spinner is visible and is animating
 */
- (BOOL)isAnimating;
@end
