pkgname="openutils-sstring"
pkgver="2.7.0"
pkgrel="8"
pkgdesc="SSTRING : The String Manipulation Library"
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("42688c0c317969e5930a643c9989323808f256555cc9537023ba7344571a03ec263484302e6d39cba532beb5ffc1442523ac6ae4d7fa340fc0469bf72ed836c1")

package() {
	echo "SSTRING : The String Manipulation Library"
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
