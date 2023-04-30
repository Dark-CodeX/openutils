pkgname="openutils-sstring"
pkgver="2.7.7"
pkgrel="8"
pkgdesc="SSTRING : The String Manipulation Library"
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("7602d5ca258298422c94eb1437d938e0dbc3f8326d5b266ebbe13a8cd8396109e8e3f5cdd0b2d6d1ea68fd1df29bf198888e444ce1584a45a4832171d3b1bc6f")

package() {
	echo "SSTRING : The String Manipulation Library"
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
