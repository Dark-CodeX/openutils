pkgname="openutils-vector"
pkgver="1.6.1"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("8c302f37e411ace338cca53b005337b2b6a11cc34c77263dd07501415731692658396f7e6efe88fa71bb11eeffe1846588652b65fa02ad551fc5e68a4dbf3eb0" "22e834a3cd0d42d1e2d7161b10adb722c69d133fe50e45adef6c51afcfe28fd95f08fca0f77aa834929b7e4bb60c4160dad5df86c8ca7e3391e7aaf5f05637e9")

package() {
	echo "Vectors in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}