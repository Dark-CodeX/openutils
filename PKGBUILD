pkgname="openutils-sstring"
pkgver="2.7.7"
pkgrel="8"
pkgdesc="SSTRING : The String Manipulation Library"
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("eed85a7ba5f68459dfb4428852adaaf23f0a6842d872b949101959bce9b18249513f6614b624f54f73661b210864dfb7bec33496140b29e0c2b644c98a8656f2")

package() {
	echo "SSTRING : The String Manipulation Library"
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
