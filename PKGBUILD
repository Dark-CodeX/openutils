pkgname="openutils-map"
pkgver="1.6.5"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.h" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/prototype_err.h")

sha512sums=("418accdd0d9924011ba714796fe748d7d9e0ccedde569efaecbeebef845b944847fcf8464048b59657de53ab5b7261e84df936f5f857395da965e853e930c68b" "c7868d6fb2cc2112858bd2f732f9aad3ef4377d76ae9acd1d0039c0dd316cbc947ae684223db200083db3e9fda0f65ee9ad3ec94842392060aae31ebe66d0228" "19c136c9f35bb1d4a65a1b32cbe9f202fd0841c2fabaed72b40c4edf4a69568eabedbe5f0d7e99c99141eca6faf9694f6531cbb5418437b6bb66fece1a0f6456")

package() {
	echo "Memory Safe Map Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/map"
	cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
	cp "${srcdir}/map.h" "${pkgdir}/usr/include/openutils/map/map.h"
	cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/map/prototype_err.h"
	echo "Done!"
}
