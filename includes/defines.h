/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   defines.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asaba <asaba@student.le-101.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/04 12:27:54 by slopez       #+#   ##    ##    #+#       */
/*   Updated: 2019/05/29 20:08:13 by asaba       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 1920
# define HEIGHT 1080

# define HALF_WIDTH 1920 * 0.5
# define HALF_HEIGHT 1080 * 0.5

# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_Q 12
# define K_E 14
# define K_SPACE 49
# define K_ESC 53


#define MIN(a,b)				(((a) < (b)) ? (a) : (b))
#define MAX(a,b)				(((a) > (b)) ? (a) : (b))
#define CLAMP(a, mi, ma)      MIN(MAX(a,mi),ma)
#endif
