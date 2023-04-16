pkgname="openutils-sstring"
pkgver="2.7.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("1996ecfc1f2e4aa2cc30370f9f864f7f7083a63fe7f78090355609b75bac68abf2d9399aee15ef37632891e4508cffaa0a8fbec5a9b61925203d34f04b0821b9")

package() {
	echo "Memory Safe String Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
