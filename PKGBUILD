pkgname="openutils-date_time"
pkgver="1.1.0"
pkgrel="1"
pkgdesc="Date and time classes for C++."
arch=("x86_64" "i686")
conflicts=('openutils-date_time')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/date.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/date-time/main/date-time/time.hh")

sha512sums=(
	"31e8b9b91910d78e836097c616adb72dbbcadf7fc32ae5323def8b109fe1cdee3072e3e8b19d9a003ba78c57c243ebdd6de6c07ac245f6d5a60e8389115e9a74"
	"a4d3ba59c89badd8c3196ef8a58ee0d359a01a93bd19a0f27aaab2e982c89c5860c1f80ef428fe0f129ec52ae86a6f6af8256a3542010e9767a5b3c14eec7199")

package() {
	echo "Date and time classes for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/date-time"
	cp "${srcdir}/date.hh" "${pkgdir}/usr/include/openutils/date-time/date.hh"
	cp "${srcdir}/time.hh" "${pkgdir}/usr/include/openutils/date-time/time.hh"
	echo "Done!"
}
