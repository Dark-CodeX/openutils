pkgname="openutils-optional"
pkgver="1.6.0"
pkgrel="2"
pkgdesc="OPTIONAL : The Error Handling Library"
arch=("x86_64" "i686")
conflicts=('openutils-optional')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/optional/master/optional/optional.hh")

sha512sums=("a0eadaffbe3da4945741deacad236359e2ee1f8eab60e1d92099894cdc6a9e09f2ffdbebbb2c03881914a413c03887272c957a7aa8c315078fbd205427f5a058")

package() {
	echo "OPTIONAL : The Error Handling Library"
	mkdir -p "${pkgdir}/usr/include/openutils/optional"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/optional/optional.hh"
	echo "Done!"
}
